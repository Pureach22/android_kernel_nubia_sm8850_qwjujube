__int64 __fastcall winner_show(__int64 a1)
{
  __int64 v2; // x21
  __int64 v3; // x22
  int v4; // w9
  __int64 v5; // x0
  unsigned int v6; // w0
  __int64 v7; // x2
  __int64 v8; // x0
  unsigned int v9; // w8
  const char *v10; // x2
  __int64 result; // x0
  unsigned int v12; // w19
  __int64 v13; // [xsp+8h] [xbp-18h] BYREF
  int v14; // [xsp+10h] [xbp-10h]
  int v15; // [xsp+14h] [xbp-Ch]
  __int64 v16; // [xsp+18h] [xbp-8h]

  v16 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD *)(a1 + 128);
  v13 = 0x10000800DLL;
  v3 = *(_QWORD *)(v2 + 16);
  v4 = *(_DWORD *)(v2 + 8);
  v14 = 23;
  v15 = v4;
  mutex_lock(v3 + 16);
  v5 = *(_QWORD *)(v3 + 8);
  *(_DWORD *)(v3 + 64) = 0;
  v6 = pmic_glink_write(v5, &v13, 16);
  if ( v6 )
  {
    v12 = v6;
LABEL_11:
    mutex_unlock(v3 + 16);
    printk(&unk_798A, "winner_show", *(_QWORD *)v2);
    result = v12;
    goto LABEL_8;
  }
  if ( !(unsigned int)wait_for_completion_timeout(v3 + 64, 250) )
  {
    printk(&unk_750C, "battery_dbg_write", v7);
    v12 = -110;
    goto LABEL_11;
  }
  v8 = mutex_unlock(v3 + 16);
  if ( !*(_DWORD *)(v2 + 192) )
  {
    v10 = (const char *)&unk_764F;
    goto LABEL_7;
  }
  v9 = *(_DWORD *)(v2 + 196);
  if ( v9 < 0x21 )
  {
    v10 = (const char *)(v3 + 12LL * v9 + 4384);
LABEL_7:
    seq_printf(a1, "%s\n", v10);
    result = 0;
LABEL_8:
    _ReadStatusReg(SP_EL0);
    return result;
  }
  __break(0x5512u);
  return voters_open(v8);
}
