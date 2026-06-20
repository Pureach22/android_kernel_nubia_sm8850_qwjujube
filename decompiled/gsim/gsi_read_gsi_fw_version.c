__int64 __fastcall gsi_read_gsi_fw_version(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  const char *v7; // x2
  void (*v8)(void); // x8
  int fw_version; // w22
  void (*v10)(void); // x8
  int v11; // w0
  __int64 result; // x0
  __int64 v13; // [xsp+8h] [xbp-18h] BYREF
  int v14; // [xsp+10h] [xbp-10h]
  __int64 v15; // [xsp+18h] [xbp-8h]

  v15 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v14 = 0;
  v13 = 0;
  if ( *(_DWORD *)(gsi_ctx + 16) > 7u )
  {
    v8 = *(void (**)(void))(gsi_ctx + 152);
    if ( *((_DWORD *)v8 - 1) != -440107680 )
      __break(0x8228u);
    v8();
    fw_version = gsi_get_fw_version((int *)&v13);
    v10 = *(void (**)(void))(gsi_ctx + 160);
    if ( *((_DWORD *)v10 - 1) != -440107680 )
      __break(0x8228u);
    v10();
    if ( !fw_version )
    {
      v11 = scnprintf(dbg_buff, 4096, "hw=%d\nflavor=%d\nfw=%d\n", (unsigned int)v13);
      goto LABEL_10;
    }
    v7 = "Fail to read GSI FW version\n";
  }
  else
  {
    v7 = "This feature only support on GSI2.9+\n";
  }
  v11 = scnprintf(dbg_buff, 4096, v7, a4);
LABEL_10:
  result = simple_read_from_buffer(a2, a3, a4, dbg_buff, v11);
  _ReadStatusReg(SP_EL0);
  return result;
}
