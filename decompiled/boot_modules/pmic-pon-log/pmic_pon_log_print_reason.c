__int64 __fastcall pmic_pon_log_print_reason(__int64 a1, int a2, char a3, const char **a4)
{
  _BOOL4 v9; // w27
  unsigned int v10; // w23
  const char *v12; // x3
  const char *v13; // x3
  const char *v14; // x3
  const char *v15; // x3
  const char *v16; // x3
  const char *v17; // x3
  const char *v18; // x3

  if ( !a3 )
    return (unsigned int)scnprintf(a1, a2, "None");
  v9 = (a3 & 1) == 0;
  if ( (a3 & 1) != 0 )
    v10 = scnprintf(a1, a2, "%s%s", (const char *)&unk_7A17, *a4);
  else
    v10 = 0;
  if ( (a3 & 2) != 0 )
  {
    if ( (a3 & 1) != 0 )
      v12 = ", ";
    else
      v12 = (const char *)&unk_7A17;
    v9 = 0;
    v10 += scnprintf(a1 + (int)v10, (int)(a2 - v10), "%s%s", v12, a4[1]);
    if ( (a3 & 4) == 0 )
    {
LABEL_8:
      if ( (a3 & 8) == 0 )
        goto LABEL_9;
      goto LABEL_22;
    }
  }
  else if ( (a3 & 4) == 0 )
  {
    goto LABEL_8;
  }
  if ( v9 )
    v13 = (const char *)&unk_7A17;
  else
    v13 = ", ";
  v9 = 0;
  v10 += scnprintf(a1 + (int)v10, (int)(a2 - v10), "%s%s", v13, a4[2]);
  if ( (a3 & 8) == 0 )
  {
LABEL_9:
    if ( (a3 & 0x10) == 0 )
      goto LABEL_10;
    goto LABEL_26;
  }
LABEL_22:
  if ( v9 )
    v14 = (const char *)&unk_7A17;
  else
    v14 = ", ";
  v9 = 0;
  v10 += scnprintf(a1 + (int)v10, (int)(a2 - v10), "%s%s", v14, a4[3]);
  if ( (a3 & 0x10) == 0 )
  {
LABEL_10:
    if ( (a3 & 0x20) == 0 )
      goto LABEL_11;
    goto LABEL_30;
  }
LABEL_26:
  if ( v9 )
    v15 = (const char *)&unk_7A17;
  else
    v15 = ", ";
  v9 = 0;
  v10 += scnprintf(a1 + (int)v10, (int)(a2 - v10), "%s%s", v15, a4[4]);
  if ( (a3 & 0x20) == 0 )
  {
LABEL_11:
    if ( (a3 & 0x40) == 0 )
      goto LABEL_12;
    goto LABEL_34;
  }
LABEL_30:
  if ( v9 )
    v16 = (const char *)&unk_7A17;
  else
    v16 = ", ";
  v9 = 0;
  v10 += scnprintf(a1 + (int)v10, (int)(a2 - v10), "%s%s", v16, a4[5]);
  if ( (a3 & 0x40) == 0 )
  {
LABEL_12:
    if ( (a3 & 0x80) == 0 )
      return v10;
    goto LABEL_38;
  }
LABEL_34:
  if ( v9 )
    v17 = (const char *)&unk_7A17;
  else
    v17 = ", ";
  v9 = 0;
  v10 += scnprintf(a1 + (int)v10, (int)(a2 - v10), "%s%s", v17, a4[6]);
  if ( a3 < 0 )
  {
LABEL_38:
    if ( v9 )
      v18 = (const char *)&unk_7A17;
    else
      v18 = ", ";
    v10 += scnprintf(a1 + (int)v10, (int)(a2 - v10), "%s%s", v18, a4[7]);
  }
  return v10;
}
