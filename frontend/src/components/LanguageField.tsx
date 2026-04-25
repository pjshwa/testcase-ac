import { useI18n } from "@/lib/i18n";
import { cn } from "@/lib/utils";
import { LANGUAGES, type LanguageValue } from "@/types";

type LanguageFieldProps = {
  id: string;
  value: LanguageValue;
  onChange: (value: LanguageValue) => void;
  orientation?: "vertical" | "horizontal";
  className?: string;
};

export default function LanguageField({
  id,
  value,
  onChange,
  orientation = "vertical",
  className,
}: LanguageFieldProps) {
  const { t } = useI18n();

  return (
    <div
      className={cn(
        orientation === "horizontal" ? "flex flex-wrap items-center gap-3" : "flex flex-col gap-2",
        className,
      )}
    >
      <label htmlFor={id} className="text-sm font-medium">
        {t("problem.language")}
      </label>
      <select
        id={id}
        value={value}
        onChange={(event) => onChange(event.target.value as LanguageValue)}
        className="h-10 rounded-md border border-input bg-background px-3 py-2 text-sm text-foreground focus-visible:outline-none focus-visible:ring-2 focus-visible:ring-ring focus-visible:ring-offset-2"
      >
        {LANGUAGES.map((language) => (
          <option key={language.value} value={language.value}>
            {language.label}
          </option>
        ))}
      </select>
    </div>
  );
}
