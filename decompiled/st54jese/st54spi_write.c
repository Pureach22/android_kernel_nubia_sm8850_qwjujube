__int64 __fastcall st54spi_write(__int64 a1, int a2, size_t a3)
{
  __int64 result; // x0
  __int64 v4; // x22
  __int64 v6; // x0
  __int64 v8; // x0
  __int64 v9; // x8
  __int64 v10; // x20
  __int64 v11; // x8
  __int64 v12; // x19
  int v13; // w0
  __int64 v14; // x19
  __int64 v15; // x0
  _QWORD v16[6]; // [xsp+0h] [xbp-120h] BYREF
  __int64 v17; // [xsp+30h] [xbp-F0h]
  __int64 v18; // [xsp+38h] [xbp-E8h]
  __int64 v19; // [xsp+40h] [xbp-E0h]
  __int64 v20; // [xsp+48h] [xbp-D8h]
  __int64 v21; // [xsp+50h] [xbp-D0h]
  _QWORD v22[5]; // [xsp+58h] [xbp-C8h] BYREF
  int v23; // [xsp+80h] [xbp-A0h]
  int v24; // [xsp+84h] [xbp-9Ch]
  __int64 v25; // [xsp+88h] [xbp-98h]
  __int64 v26; // [xsp+90h] [xbp-90h]
  __int64 v27; // [xsp+98h] [xbp-88h]
  __int64 v28; // [xsp+A0h] [xbp-80h]
  __int64 v29; // [xsp+A8h] [xbp-78h]
  __int64 v30; // [xsp+B0h] [xbp-70h]
  __int64 v31; // [xsp+B8h] [xbp-68h]
  __int64 v32; // [xsp+C0h] [xbp-60h]
  __int64 v33; // [xsp+C8h] [xbp-58h]
  __int64 v34; // [xsp+D0h] [xbp-50h]
  __int64 v35; // [xsp+D8h] [xbp-48h]
  _QWORD *v36; // [xsp+E0h] [xbp-40h] BYREF
  _QWORD *v37; // [xsp+E8h] [xbp-38h]
  __int64 v38; // [xsp+F0h] [xbp-30h]
  __int64 v39; // [xsp+F8h] [xbp-28h]
  __int64 v40; // [xsp+100h] [xbp-20h]
  _QWORD v41[3]; // [xsp+108h] [xbp-18h] BYREF

  v41[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( (unsigned int)bufsiz >= a3 )
  {
    v4 = *(_QWORD *)(a1 + 32);
    v6 = *(_QWORD *)(v4 + 8);
    if ( !v6 )
      v6 = *(_QWORD *)(v4 + 16);
    v8 = dev_info(v6, "st54spi Write: %zu bytes\n", a3);
    if ( v4 && *(_DWORD *)(v4 + 128) && *(_QWORD *)(v4 + 184) )
    {
      v9 = ktime_get(v8) - *(_QWORD *)(v4 + 184);
      if ( v9 <= 9999999 )
        usleep_range_state(1000 * (10 - v9 / 1000000), 1000 * (11 - v9 / 1000000), 2);
      *(_QWORD *)(v4 + 184) = 0;
    }
    mutex_lock(v4 + 40);
    if ( a3 >> 31 )
    {
      __break(0x800u);
      v14 = -14;
    }
    else
    {
      v10 = *(_QWORD *)(v4 + 96);
      _check_object_size(v10, a3, 0);
      if ( inline_copy_from_user(v10, a2, a3) )
      {
        v14 = -14;
      }
      else
      {
        v37 = nullptr;
        v38 = 0;
        v35 = 0;
        v36 = nullptr;
        v33 = 0;
        v34 = 0;
        v11 = *(_QWORD *)(v4 + 96);
        v31 = 0;
        v32 = 0;
        v29 = 0;
        v30 = 0;
        v22[2] = 0;
        v22[3] = v11;
        LODWORD(v11) = *(_DWORD *)(v4 + 120);
        v27 = 0;
        v28 = 0;
        LODWORD(v33) = v11;
        v25 = 0;
        v26 = 0;
        v22[4] = 0;
        v24 = 0;
        v23 = a3;
        v20 = 0;
        v21 = 0;
        v18 = 0;
        v19 = 0;
        v17 = 0;
        v22[0] = v22;
        v22[1] = v22;
        v36 = v16;
        v37 = v16;
        v16[1] = &v36;
        memset(&v16[2], 0, 32);
        v16[0] = &v36;
        v39 = 0;
        v40 = 0;
        v41[0] = v41;
        v41[1] = v41;
        raw_spin_lock_irq(v4 + 4);
        v12 = *(_QWORD *)(v4 + 8);
        raw_spin_unlock_irq(v4 + 4);
        if ( v12 )
        {
          v13 = spi_sync(v12, v16);
          if ( !v13 )
            v13 = HIDWORD(v17);
        }
        else
        {
          v13 = -108;
        }
        v14 = v13;
      }
    }
    mutex_unlock(v4 + 40);
    v15 = *(_QWORD *)(v4 + 8);
    if ( !v15 )
      v15 = *(_QWORD *)(v4 + 16);
    dev_info(v15, "st54spi Write: status: %zd\n", v14);
    result = v14;
  }
  else
  {
    result = -90;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
