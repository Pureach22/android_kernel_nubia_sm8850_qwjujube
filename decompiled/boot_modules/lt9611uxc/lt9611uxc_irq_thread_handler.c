__int64 __fastcall lt9611uxc_irq_thread_handler(__int64 a1, __int64 a2)
{
  char v3; // w20
  __int64 v4; // x8
  __int16 v5; // w10
  __int64 v6; // x0
  __int64 v7; // x8
  __int16 v8; // w10
  __int64 v9; // x0
  int v10; // w9
  int v11; // w10
  void *v12; // x0
  char v13; // w8
  _BYTE v15[4]; // [xsp+0h] [xbp-20h] BYREF
  _BYTE v16[4]; // [xsp+4h] [xbp-1Ch] BYREF
  __int16 v17; // [xsp+8h] [xbp-18h] BYREF
  int v18; // [xsp+Ah] [xbp-16h]
  __int16 v19; // [xsp+Eh] [xbp-12h]
  __int64 v20; // [xsp+10h] [xbp-10h]
  __int64 v21; // [xsp+18h] [xbp-8h]

  v21 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v16[0] = 0;
  v15[0] = 0;
  mutex_lock(a2 + 328);
  v3 = *(_BYTE *)(a2 + 4019);
  lt9611uxc_ctl_en(a2);
  v4 = *(_QWORD *)(a2 + 3160);
  v5 = *(_WORD *)(v4 + 2);
  v18 = 0x20000;
  *(_QWORD *)(a2 + 3760) = 0;
  *(_QWORD *)(a2 + 3768) = 0;
  *(_QWORD *)(a2 + 3776) = 0;
  *(_QWORD *)(a2 + 3784) = 0;
  *(_QWORD *)(a2 + 3792) = 0;
  *(_QWORD *)(a2 + 3800) = 0;
  *(_QWORD *)(a2 + 3808) = 0;
  *(_QWORD *)(a2 + 3816) = 0;
  *(_QWORD *)(a2 + 3824) = 0;
  *(_QWORD *)(a2 + 3832) = 0;
  *(_QWORD *)(a2 + 3840) = 0;
  *(_QWORD *)(a2 + 3848) = 0;
  *(_QWORD *)(a2 + 3856) = 0;
  *(_QWORD *)(a2 + 3864) = 0;
  *(_QWORD *)(a2 + 3872) = 0;
  *(_QWORD *)(a2 + 3880) = 0;
  *(_WORD *)(a2 + 3760) = -20225;
  v6 = *(_QWORD *)(v4 + 24);
  v17 = v5;
  v19 = 0;
  v20 = a2 + 3760;
  if ( (int)i2c_transfer(v6, &v17, 1) <= 0 )
    printk(&unk_A9C9, "lt9611uxc_write_byte");
  if ( (unsigned int)lt9611uxc_read((_QWORD *)a2, 34, v16, 1u) )
  {
    v12 = &unk_AA54;
LABEL_12:
    printk(v12, "lt9611uxc_irq_thread_handler");
    goto LABEL_13;
  }
  if ( !v16[0] )
  {
    v12 = &unk_ACF5;
    goto LABEL_12;
  }
  v7 = *(_QWORD *)(a2 + 3160);
  v8 = *(_WORD *)(v7 + 2);
  v18 = 0x20000;
  *(_QWORD *)(a2 + 3760) = 0;
  *(_QWORD *)(a2 + 3768) = 0;
  *(_QWORD *)(a2 + 3776) = 0;
  *(_QWORD *)(a2 + 3784) = 0;
  *(_QWORD *)(a2 + 3792) = 0;
  *(_QWORD *)(a2 + 3800) = 0;
  *(_QWORD *)(a2 + 3808) = 0;
  *(_QWORD *)(a2 + 3816) = 0;
  *(_QWORD *)(a2 + 3824) = 0;
  *(_QWORD *)(a2 + 3832) = 0;
  *(_QWORD *)(a2 + 3840) = 0;
  *(_QWORD *)(a2 + 3848) = 0;
  *(_QWORD *)(a2 + 3856) = 0;
  *(_QWORD *)(a2 + 3864) = 0;
  *(_QWORD *)(a2 + 3872) = 0;
  *(_QWORD *)(a2 + 3880) = 0;
  *(_BYTE *)(a2 + 3760) = 34;
  v9 = *(_QWORD *)(v7 + 24);
  v17 = v8;
  v19 = 0;
  v20 = a2 + 3760;
  if ( (int)i2c_transfer(v9, &v17, 1) <= 0 )
    printk(&unk_A9C9, "lt9611uxc_write_byte");
  lt9611uxc_read((_QWORD *)a2, 35, v15, 1u);
  v10 = (v15[0] >> 1) & 1;
  v11 = v15[0] >> 1;
  *(_BYTE *)(a2 + 4019) = v15[0] & 1;
  *(_BYTE *)(a2 + 4020) = v10;
  *(_BYTE *)(a2 + 4023) = (v11 & 1) != 0;
LABEL_13:
  lt9611uxc_ctl_disable(a2);
  v13 = *(_BYTE *)(a2 + 4019);
  if ( (*(_BYTE *)(a2 + 4021) & 1) == 0 && (*(_BYTE *)(a2 + 4019) & 1) != 0 )
    *(_BYTE *)(a2 + 4022) = 1;
  if ( (v3 & 1) != 0 )
  {
    if ( (v13 & 1) != 0 )
      goto LABEL_22;
    goto LABEL_21;
  }
  if ( (v13 & 1) == 0 )
  {
LABEL_21:
    *(_BYTE *)(a2 + 4016) = 0;
LABEL_22:
    mutex_unlock(a2 + 328);
    goto LABEL_23;
  }
  *(_BYTE *)(a2 + 4016) = 1;
  mutex_unlock(a2 + 328);
  _wake_up(a2 + 3480, 3, 0, 0);
LABEL_23:
  msleep(50);
  if ( (v16[0] & 2) != 0 && *(_BYTE *)(a2 + 4021) == 1 )
    queue_work_on(32, *(_QWORD *)(a2 + 3440), a2 + 3448);
  _ReadStatusReg(SP_EL0);
  return 1;
}
