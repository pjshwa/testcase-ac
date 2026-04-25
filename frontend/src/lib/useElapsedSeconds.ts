import { useEffect, useState } from "react";

const ELAPSED_TIMER_INTERVAL_MS = 100;

export function useElapsedSeconds(isRunning: boolean): string {
  const [elapsedTenths, setElapsedTenths] = useState(0);

  useEffect(() => {
    if (!isRunning) {
      setElapsedTenths(0);
      return;
    }

    const startedAt = Date.now();
    setElapsedTenths(0);
    const timer = window.setInterval(() => {
      setElapsedTenths(Math.floor((Date.now() - startedAt) / ELAPSED_TIMER_INTERVAL_MS));
    }, ELAPSED_TIMER_INTERVAL_MS);
    return () => window.clearInterval(timer);
  }, [isRunning]);

  return (elapsedTenths / 10).toFixed(1);
}
