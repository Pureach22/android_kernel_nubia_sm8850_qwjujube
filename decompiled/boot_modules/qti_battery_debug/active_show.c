__int64 __fastcall active_show(__int64 a1)
{
  __int64 v2; // x21
  __int64 v3; // x22
  int v4; // w9
  unsigned int v5; // w0
  __int64 v6; // x2
  __int64 result; // x0
  unsigned int v8; // w19
  __int64 v9; // [xsp+8h] [xbp-18h] BYREF
  int v10; // [xsp+10h] [xbp-10h]
  int v11; // [xsp+14h] [xbp-Ch]
  __int64 v12; // [xsp+18h] [xbp-8h]

  v12 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD *)(a1 + 128);
  v9 = 0x10000800DLL;
  v3 = *(_QWORD *)(v2 + 16);
  v4 = *(_DWORD *)(v2 + 8);
  v10 = 23;
  v11 = v4;
  mutex_lock(v3 + 16);
  *(_DWORD *)(v3 + 64) = 0;
  v5 = pmic_glink_write(*(_QWORD *)(v3 + 8), &v9, 16);
  if ( v5 )
  {
    v8 = v5;
LABEL_7:
    mutex_unlock(v3 + 16);
    printk(&unk_798A, "active_show", *(_QWORD *)v2);
    result = v8;
    goto LABEL_4;
  }
  if ( !(unsigned int)wait_for_completion_timeout(v3 + 64, 250) )
  {
    printk(&unk_750C, "battery_dbg_write", v6);
    v8 = -110;
    goto LABEL_7;
  }
  mutex_unlock(v3 + 16);
  seq_printf(a1, "%#lx\n", *(unsigned int *)(v2 + 192));
  result = 0;
LABEL_4:
  _ReadStatusReg(SP_EL0);
  return result;
}
