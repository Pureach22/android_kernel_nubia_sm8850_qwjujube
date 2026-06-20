__int64 __fastcall votes_show(__int64 a1)
{
  __int64 v2; // x21
  __int64 v3; // x22
  int v4; // w9
  unsigned int v5; // w0
  __int64 v6; // x2
  __int64 v7; // x22
  char v8; // w8
  __int64 v9; // x21
  unsigned __int64 v10; // x8
  unsigned __int64 v11; // x24
  __int64 result; // x0
  unsigned int v13; // w19
  __int64 v14; // [xsp+8h] [xbp-18h] BYREF
  int v15; // [xsp+10h] [xbp-10h]
  int v16; // [xsp+14h] [xbp-Ch]
  __int64 v17; // [xsp+18h] [xbp-8h]

  v17 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD *)(a1 + 128);
  v14 = 0x10000800DLL;
  v3 = *(_QWORD *)(v2 + 16);
  v4 = *(_DWORD *)(v2 + 8);
  v15 = 23;
  v16 = v4;
  mutex_lock(v3 + 16);
  *(_DWORD *)(v3 + 64) = 0;
  v5 = pmic_glink_write(*(_QWORD *)(v3 + 8), &v14, 16);
  if ( v5 )
  {
    v13 = v5;
LABEL_10:
    mutex_unlock(v3 + 16);
    printk(&unk_798A, "votes_show", *(_QWORD *)v2);
    result = v13;
    goto LABEL_7;
  }
  if ( !(unsigned int)wait_for_completion_timeout(v3 + 64, 250) )
  {
    printk(&unk_750C, "battery_dbg_write", v6);
    v13 = -110;
    goto LABEL_10;
  }
  mutex_unlock(v3 + 16);
  v7 = *(unsigned int *)(v2 + 192);
  v8 = 0;
  v9 = v2 + 64;
  do
  {
    v10 = (-1LL << v8) & v7;
    if ( !v10 )
      break;
    v11 = __clz(__rbit64(v10));
    seq_printf(a1, "%d ", *(_DWORD *)(v9 + 4 * v11));
    v8 = v11 + 1;
  }
  while ( v11 < 0x1F );
  seq_putc(a1, 10);
  result = 0;
LABEL_7:
  _ReadStatusReg(SP_EL0);
  return result;
}
