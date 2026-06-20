__int64 __fastcall lt9611uxc_connector_detect(__int64 a1, char a2)
{
  __int64 v3; // x8
  __int16 v4; // w10
  __int64 v5; // x0
  __int64 result; // x0
  _BYTE v7[4]; // [xsp+4h] [xbp-1Ch] BYREF
  __int16 v8; // [xsp+8h] [xbp-18h] BYREF
  int v9; // [xsp+Ah] [xbp-16h]
  __int16 v10; // [xsp+Eh] [xbp-12h]
  __int64 v11; // [xsp+10h] [xbp-10h]
  __int64 v12; // [xsp+18h] [xbp-8h]

  v12 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v7[0] = 0;
  *(_DWORD *)(a1 + 2792) = 2;
  if ( (a2 & 1) != 0 )
  {
    mutex_lock(a1 - 48);
    lt9611uxc_ctl_en((_QWORD *)(a1 - 376));
    v3 = *(_QWORD *)(a1 + 2784);
    v4 = *(_WORD *)(v3 + 2);
    v9 = 0x20000;
    *(_QWORD *)(a1 + 3384) = 0;
    *(_QWORD *)(a1 + 3392) = 0;
    *(_QWORD *)(a1 + 3400) = 0;
    *(_QWORD *)(a1 + 3408) = 0;
    *(_QWORD *)(a1 + 3416) = 0;
    *(_QWORD *)(a1 + 3424) = 0;
    *(_QWORD *)(a1 + 3432) = 0;
    *(_QWORD *)(a1 + 3440) = 0;
    *(_QWORD *)(a1 + 3448) = 0;
    *(_QWORD *)(a1 + 3456) = 0;
    *(_QWORD *)(a1 + 3464) = 0;
    *(_QWORD *)(a1 + 3472) = 0;
    *(_QWORD *)(a1 + 3480) = 0;
    *(_QWORD *)(a1 + 3488) = 0;
    *(_QWORD *)(a1 + 3496) = 0;
    *(_QWORD *)(a1 + 3504) = 0;
    *(_WORD *)(a1 + 3384) = -20225;
    v5 = *(_QWORD *)(v3 + 24);
    v8 = v4;
    v10 = 0;
    v11 = a1 + 3384;
    if ( (int)i2c_transfer(v5, &v8, 1) <= 0 )
      printk(&unk_A9C9, "lt9611uxc_write_byte");
    if ( (unsigned int)lt9611uxc_read((_QWORD *)(a1 - 376), 35, v7, 1u) )
    {
      printk(&unk_B48B, "lt9611uxc_connector_detect");
    }
    else if ( (v7[0] & 2) != 0 )
    {
      *(_DWORD *)(a1 + 2792) = 1;
    }
    lt9611uxc_ctl_disable((_QWORD *)(a1 - 376));
    mutex_unlock(a1 - 48);
    msleep(50);
    result = *(unsigned int *)(a1 + 2792);
  }
  else
  {
    result = 1;
    *(_DWORD *)(a1 + 2792) = 1;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
