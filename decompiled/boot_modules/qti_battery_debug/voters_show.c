__int64 __fastcall voters_show(__int64 a1)
{
  __int64 v2; // x21
  __int64 v3; // x22
  int v4; // w9
  __int64 v5; // x0
  unsigned int v6; // w0
  __int64 v7; // x2
  __int64 v8; // x21
  char v9; // w8
  __int64 v10; // x22
  unsigned __int64 v11; // x8
  unsigned __int64 v12; // x25
  __int64 result; // x0
  unsigned int v14; // w19
  __int64 v15; // [xsp+8h] [xbp-18h] BYREF
  int v16; // [xsp+10h] [xbp-10h]
  int v17; // [xsp+14h] [xbp-Ch]
  __int64 v18; // [xsp+18h] [xbp-8h]

  v18 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD *)(a1 + 128);
  v15 = 0x10000800DLL;
  v3 = *(_QWORD *)(v2 + 16);
  v4 = *(_DWORD *)(v2 + 8);
  v16 = 23;
  v17 = v4;
  mutex_lock(v3 + 16);
  v5 = *(_QWORD *)(v3 + 8);
  *(_DWORD *)(v3 + 64) = 0;
  v6 = pmic_glink_write(v5, &v15, 16);
  if ( v6 )
  {
    v14 = v6;
LABEL_10:
    mutex_unlock(v3 + 16);
    printk(&unk_798A, "voters_show", *(_QWORD *)v2);
    result = v14;
    goto LABEL_7;
  }
  if ( !(unsigned int)wait_for_completion_timeout(v3 + 64, 250) )
  {
    printk(&unk_750C, "battery_dbg_write", v7);
    v14 = -110;
    goto LABEL_10;
  }
  mutex_unlock(v3 + 16);
  v8 = *(unsigned int *)(v2 + 192);
  v9 = 0;
  v10 = v3 + 4384;
  do
  {
    v11 = (-1LL << v9) & v8;
    if ( !v11 )
      break;
    v12 = __clz(__rbit64(v11));
    seq_printf(a1, "%s ", (const char *)(v10 + 12LL * (unsigned int)v12));
    v9 = v12 + 1;
  }
  while ( v12 < 0x1F );
  seq_putc(a1, 10);
  result = 0;
LABEL_7:
  _ReadStatusReg(SP_EL0);
  return result;
}
