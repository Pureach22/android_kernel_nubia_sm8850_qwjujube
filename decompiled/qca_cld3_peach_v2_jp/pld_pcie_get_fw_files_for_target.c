__int64 __fastcall pld_pcie_get_fw_files_for_target(__int64 a1, char *s, unsigned int a3, unsigned int a4)
{
  __int64 result; // x0
  _QWORD v9[5]; // [xsp+8h] [xbp-98h] BYREF
  _QWORD v10[5]; // [xsp+30h] [xbp-70h] BYREF
  _QWORD v11[5]; // [xsp+58h] [xbp-48h] BYREF
  _QWORD v12[2]; // [xsp+80h] [xbp-20h] BYREF
  int v13; // [xsp+90h] [xbp-10h]
  __int64 v14; // [xsp+98h] [xbp-8h]

  v14 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( s )
  {
    v13 = 0;
    v12[0] = 0;
    v12[1] = 0;
    memset(v11, 0, sizeof(v11));
    memset(v10, 0, sizeof(v10));
    memset(v9, 0, sizeof(v9));
    memset(s, 0, 0x8F7u);
    result = cnss_get_fw_files_for_target(a1, v9, a3, a4);
    if ( !(_DWORD)result )
    {
      scnprintf(s, 255, "peach_v2/%s", (const char *)v9);
      scnprintf(s + 255, 255, "peach_v2/%s", (const char *)&v9[2] + 4);
      scnprintf(s + 510, 255, "peach_v2/%s", (const char *)v10);
      scnprintf(s + 765, 255, "peach_v2/%s", (const char *)&v10[2] + 4);
      scnprintf(s + 1020, 255, "peach_v2/%s", (const char *)v11);
      scnprintf(s + 1275, 255, "peach_v2/%s", (const char *)&v11[2] + 4);
      scnprintf(s + 1530, 255, "peach_v2/%s", (const char *)v12);
      result = 0;
    }
  }
  else
  {
    result = 4294967277LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
