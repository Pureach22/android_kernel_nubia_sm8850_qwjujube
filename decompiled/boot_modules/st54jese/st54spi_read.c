__int64 __fastcall st54spi_read(__int64 a1, __int64 a2, unsigned __int64 a3)
{
  __int64 result; // x0
  __int64 v4; // x22
  __int64 v6; // x0
  int v7; // w20
  __int64 v8; // x0
  __int64 v9; // x8
  __int64 v10; // x8
  __int64 v11; // x9
  __int64 v12; // x20
  __int64 v13; // x19
  int v14; // w0
  int v15; // w8
  __int64 v16; // x21
  __int64 v17; // x20
  __int64 v18; // x0
  __int64 v19; // x0
  _QWORD v20[6]; // [xsp+0h] [xbp-120h] BYREF
  __int64 v21; // [xsp+30h] [xbp-F0h]
  __int64 v22; // [xsp+38h] [xbp-E8h]
  __int64 v23; // [xsp+40h] [xbp-E0h]
  __int64 v24; // [xsp+48h] [xbp-D8h]
  __int64 v25; // [xsp+50h] [xbp-D0h]
  _QWORD v26[5]; // [xsp+58h] [xbp-C8h] BYREF
  int v27; // [xsp+80h] [xbp-A0h]
  int v28; // [xsp+84h] [xbp-9Ch]
  __int64 v29; // [xsp+88h] [xbp-98h]
  __int64 v30; // [xsp+90h] [xbp-90h]
  __int64 v31; // [xsp+98h] [xbp-88h]
  __int64 v32; // [xsp+A0h] [xbp-80h]
  __int64 v33; // [xsp+A8h] [xbp-78h]
  __int64 v34; // [xsp+B0h] [xbp-70h]
  __int64 v35; // [xsp+B8h] [xbp-68h]
  __int64 v36; // [xsp+C0h] [xbp-60h]
  __int64 v37; // [xsp+C8h] [xbp-58h]
  __int64 v38; // [xsp+D0h] [xbp-50h]
  __int64 v39; // [xsp+D8h] [xbp-48h]
  _QWORD *v40; // [xsp+E0h] [xbp-40h] BYREF
  _QWORD *v41; // [xsp+E8h] [xbp-38h]
  __int64 v42; // [xsp+F0h] [xbp-30h]
  __int64 v43; // [xsp+F8h] [xbp-28h]
  __int64 v44; // [xsp+100h] [xbp-20h]
  _QWORD v45[3]; // [xsp+108h] [xbp-18h] BYREF

  v45[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( (unsigned int)bufsiz >= a3 )
  {
    v4 = *(_QWORD *)(a1 + 32);
    v6 = *(_QWORD *)(v4 + 8);
    if ( !v6 )
      v6 = *(_QWORD *)(v4 + 16);
    v7 = a3;
    v8 = dev_info(v6, "st54spi Read: %zu bytes\n", a3);
    if ( v4 && *(_DWORD *)(v4 + 128) && *(_QWORD *)(v4 + 184) )
    {
      v9 = ktime_get(v8) - *(_QWORD *)(v4 + 184);
      if ( v9 <= 9999999 )
        usleep_range_state(1000 * (10 - v9 / 1000000), 1000 * (11 - v9 / 1000000), 2);
      *(_QWORD *)(v4 + 184) = 0;
    }
    mutex_lock(v4 + 40);
    v41 = nullptr;
    v42 = 0;
    v39 = 0;
    v40 = nullptr;
    v11 = *(_QWORD *)(v4 + 104);
    v10 = *(_QWORD *)(v4 + 112);
    v37 = 0;
    v38 = 0;
    v35 = 0;
    v36 = 0;
    v33 = 0;
    v34 = 0;
    v26[2] = 0;
    v26[3] = v10;
    LODWORD(v10) = *(_DWORD *)(v4 + 120);
    v26[4] = v11;
    v28 = 0;
    LODWORD(v37) = v10;
    v31 = 0;
    v32 = 0;
    v29 = 0;
    v30 = 0;
    v27 = v7;
    v24 = 0;
    v25 = 0;
    v22 = 0;
    v23 = 0;
    v21 = 0;
    v26[0] = v26;
    v26[1] = v26;
    v40 = v20;
    v41 = v20;
    v20[1] = &v40;
    memset(&v20[2], 0, 32);
    v20[0] = &v40;
    v43 = 0;
    v44 = 0;
    v45[0] = v45;
    v45[1] = v45;
    raw_spin_lock_irq(v4 + 4);
    v12 = *(_QWORD *)(v4 + 8);
    raw_spin_unlock_irq(v4 + 4);
    if ( v12 )
    {
      v14 = spi_sync(v12, v20);
      if ( v14 )
        v15 = v14;
      else
        v15 = HIDWORD(v21);
      v16 = v15;
      if ( v15 < 1 )
      {
        v13 = v15;
      }
      else
      {
        v17 = *(_QWORD *)(v4 + 104);
        _check_object_size(v17, v15, 1);
        v18 = inline_copy_to_user(a2, v17, v16);
        if ( v16 == v18 )
          v13 = -14;
        else
          v13 = v16 - v18;
      }
    }
    else
    {
      v13 = -108;
    }
    mutex_unlock(v4 + 40);
    v19 = *(_QWORD *)(v4 + 8);
    if ( !v19 )
      v19 = *(_QWORD *)(v4 + 16);
    dev_info(v19, "st54spi Read: status: %zd\n", v13);
    result = v13;
  }
  else
  {
    result = -90;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
