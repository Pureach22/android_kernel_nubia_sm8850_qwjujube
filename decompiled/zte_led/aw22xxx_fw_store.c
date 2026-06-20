__int64 __fastcall aw22xxx_fw_store(__int64 a1, int a2, char *s, __int64 a4)
{
  __int64 v5; // x20
  bool v6; // zf
  int v8; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v9; // [xsp+8h] [xbp-8h]

  v9 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *(_QWORD *)(a1 + 152);
  v8 = 0;
  if ( sscanf(s, "%x", &v8) == 1 )
  {
    v6 = v8 == 1;
    *(_BYTE *)(v5 + 734) = v8;
    if ( v6 )
      queue_work_on(32, system_wq, v5 + 512);
  }
  g_init_flg = 0;
  _ReadStatusReg(SP_EL0);
  return a4;
}
