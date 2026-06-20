__int64 __fastcall ucsi_qti_read(__int64 a1, unsigned int a2, void *a3, size_t a4)
{
  __int64 v4; // x9
  __int64 v5; // x25
  unsigned int v8; // w8
  bool v9; // cf
  unsigned __int64 v10; // x8
  unsigned int v13; // w0
  __int64 v14; // x3
  __int64 v15; // x2
  __int64 v16; // x3
  unsigned int v17; // w23
  __int64 v19; // [xsp+Ch] [xbp-14h] BYREF
  int v20; // [xsp+14h] [xbp-Ch]
  __int64 v21; // [xsp+18h] [xbp-8h]

  v4 = 528;
  v5 = a2;
  v21 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v8 = *(unsigned __int16 *)(a1 + 1360);
  if ( v8 >= 0x211 )
    v4 = 0;
  v9 = v8 >= 0x121;
  v10 = 48;
  if ( v9 )
    v10 = v4;
  if ( a2 + a4 > v10 )
  {
    printk(&unk_757A, "validate_ucsi_msg", a4, a2);
    v17 = -22;
  }
  else if ( *(_DWORD *)(a1 + 1448) )
  {
    v20 = 17;
    v19 = 0x10000800BLL;
    mutex_lock(a1 + 128);
    *(_DWORD *)(a1 + 32) = 0;
    v13 = pmic_glink_write(*(_QWORD *)(a1 + 16), &v19, 12);
    if ( (v13 & 0x80000000) != 0 )
    {
      v17 = v13;
      printk(&unk_72C1, "ucsi_qti_read", v13, v14);
    }
    else if ( (unsigned int)wait_for_completion_timeout(a1 + 32, 1250) )
    {
      if ( *(_DWORD *)(a1 + 1376) )
      {
        memcpy(a3, (const void *)(a1 + v5 + 284), a4);
        *(_DWORD *)(a1 + 1376) = 0;
        ucsi_log(a1, "read:", a2, a3, a4);
        v17 = 0;
      }
      else
      {
        v17 = -61;
      }
    }
    else
    {
      printk(&unk_7436, "ucsi_qti_read", v15, v16);
      v17 = -110;
    }
    mutex_unlock(a1 + 128);
  }
  else
  {
    v17 = 0;
  }
  _ReadStatusReg(SP_EL0);
  return v17;
}
