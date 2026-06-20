__int64 __fastcall winvote_show(__int64 a1)
{
  __int64 v2; // x21
  __int64 v3; // x22
  int v4; // w9
  unsigned int v5; // w0
  __int64 v6; // x2
  int v7; // w2
  __int64 result; // x0
  unsigned int v9; // w19
  __int64 v10; // [xsp+8h] [xbp-18h] BYREF
  int v11; // [xsp+10h] [xbp-10h]
  int v12; // [xsp+14h] [xbp-Ch]
  __int64 v13; // [xsp+18h] [xbp-8h]

  v13 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD *)(a1 + 128);
  v10 = 0x10000800DLL;
  v3 = *(_QWORD *)(v2 + 16);
  v4 = *(_DWORD *)(v2 + 8);
  v11 = 23;
  v12 = v4;
  mutex_lock(v3 + 16);
  *(_DWORD *)(v3 + 64) = 0;
  v5 = pmic_glink_write(*(_QWORD *)(v3 + 8), &v10, 16);
  if ( v5 )
  {
    v9 = v5;
LABEL_10:
    mutex_unlock(v3 + 16);
    printk(&unk_798A, "winvote_show", *(_QWORD *)v2);
    result = v9;
    goto LABEL_7;
  }
  if ( !(unsigned int)wait_for_completion_timeout(v3 + 64, 250) )
  {
    printk(&unk_750C, "battery_dbg_write", v6);
    v9 = -110;
    goto LABEL_10;
  }
  mutex_unlock(v3 + 16);
  if ( *(_DWORD *)(v2 + 192) )
    v7 = *(_DWORD *)(v2 + 28);
  else
    v7 = -22;
  seq_printf(a1, "%d\n", v7);
  result = 0;
LABEL_7:
  _ReadStatusReg(SP_EL0);
  return result;
}
