__int64 __fastcall dp_aux_hex_dump(__int64 a1, unsigned int *a2)
{
  char v4; // w8
  __int64 v5; // x21
  __int64 v6; // x5
  const char *v7; // x3
  void *v8; // x4
  __int64 result; // x0
  unsigned __int64 v10; // x8
  int v11; // w28
  unsigned __int64 StatusReg; // x27
  int v13; // w9
  bool v14; // vf
  _QWORD v15[8]; // [xsp+8h] [xbp-88h] BYREF
  char s[8]; // [xsp+48h] [xbp-48h] BYREF
  __int64 v17; // [xsp+50h] [xbp-40h]
  __int64 v18; // [xsp+58h] [xbp-38h]
  __int64 v19; // [xsp+60h] [xbp-30h]
  __int64 v20; // [xsp+68h] [xbp-28h]
  __int64 v21; // [xsp+70h] [xbp-20h]
  __int64 v22; // [xsp+78h] [xbp-18h]
  __int64 v23; // [xsp+80h] [xbp-10h]
  __int64 v24; // [xsp+88h] [xbp-8h]

  v24 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *((_BYTE *)a2 + 4);
  v5 = *((_QWORD *)a2 + 2);
  v6 = *a2;
  v22 = 0;
  v23 = 0;
  if ( (v4 & 4) != 0 )
    v7 = "I2C";
  else
    v7 = "NAT";
  v20 = 0;
  v21 = 0;
  if ( (v4 & 1) != 0 )
    v8 = &unk_21C0AE;
  else
    v8 = &unk_233DF0;
  v18 = 0;
  v19 = 0;
  *(_QWORD *)s = 0;
  v17 = 0;
  memset(v15, 0, sizeof(v15));
  result = snprintf(s, 0x40u, "%s %s %4xh(%2zu): ", v7, v8, v6, v5);
  if ( *((_QWORD *)a2 + 2) )
  {
    v10 = 0;
    v11 = 16;
    StatusReg = _ReadStatusReg(SP_EL0);
    do
    {
      v13 = v5;
      v14 = __OFSUB__((_DWORD)v5, 16);
      LODWORD(v5) = v5 - 16;
      if ( (int)v5 < 0 == v14 )
        v13 = 16;
      result = hex_dump_to_buffer(*((_QWORD *)a2 + 1) + v10, v13, 16, 1, v15, 64, 0);
      if ( (*((_QWORD *)a2 + 2) != 1 || *a2) && a1 != 224 )
        result = ipc_log_string(
                   *(_QWORD *)(a1 - 208),
                   "[d][%-4d]%s%s\n",
                   *(_DWORD *)(StatusReg + 1800),
                   s,
                   (const char *)v15);
      if ( (_drm_debug & 4) != 0 )
        result = _drm_dev_dbg(
                   0,
                   0,
                   0,
                   "[msm-dp-debug][%-4d]%s%s\n",
                   *(_DWORD *)(StatusReg + 1800),
                   s,
                   (const char *)v15);
      v10 = v11;
      v11 += 16;
    }
    while ( *((_QWORD *)a2 + 2) > v10 );
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
