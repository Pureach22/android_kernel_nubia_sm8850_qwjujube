__int64 __fastcall lt9611uxc_connector_get_modes(__int64 a1)
{
  __int64 v1; // x21
  _QWORD *v3; // x20
  __int64 v4; // x8
  _QWORD *v5; // x22
  __int16 v6; // w9
  __int64 v7; // x0
  __int64 v8; // x8
  __int16 v9; // w9
  __int64 v10; // x0
  __int64 v11; // x8
  __int16 v12; // w10
  __int64 v13; // x0
  __int64 custom; // x22
  __int64 v15; // x21
  unsigned int v16; // w21
  _QWORD *v17; // x21
  __int64 v18; // x0
  __int64 v19; // x8
  _QWORD *v20; // x19
  _QWORD *v21; // x24
  _QWORD *v22; // t1
  __int64 *v23; // x22
  __int64 *v24; // x20
  int v25; // w23
  int v26; // w0
  int v27; // w8
  int v28; // w9
  __int64 *v30; // x19
  __int64 *v31; // x8
  __int64 *v32; // x9
  __int64 *i; // x20
  __int64 v35; // x0
  __int64 v36; // x22
  __int64 v37; // x22
  char *s2; // [xsp+0h] [xbp-30h] BYREF
  __int64 v39; // [xsp+8h] [xbp-28h]
  __int64 v40; // [xsp+10h] [xbp-20h]
  __int64 v41; // [xsp+18h] [xbp-18h]
  __int64 v42; // [xsp+20h] [xbp-10h]
  __int64 v43; // [xsp+28h] [xbp-8h]

  v1 = a1 - 48;
  v3 = (_QWORD *)(a1 - 376);
  v43 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  mutex_lock(a1 - 48);
  if ( (*(_BYTE *)(a1 + 3646) & 1) != 0 || *(_BYTE *)(a1 + 3640) == 1 )
  {
    *(_BYTE *)(a1 + 3646) = 0;
    *(_BYTE *)(a1 + 3640) = 0;
    mutex_unlock(v1);
  }
  else
  {
    if ( (*(_BYTE *)(a1 + 3643) & 1) != 0 || *(_BYTE *)(a1 + 3647) != 1 )
    {
      mutex_unlock(v1);
      goto LABEL_21;
    }
    *(_BYTE *)(a1 + 3647) = 0;
    mutex_unlock(v1);
    if ( (*(_BYTE *)(a1 + 3640) & 1) == 0 )
    {
      v41 = 0;
      v42 = 0;
      v39 = 0;
      v40 = 0;
      s2 = nullptr;
      init_wait_entry(&s2, 0);
      prepare_to_wait_event(a1 + 3104, &s2, 2);
      if ( (*(_BYTE *)(a1 + 3640) & 1) != 0 )
      {
        finish_wait(a1 + 3104, &s2);
      }
      else
      {
        v35 = 500;
        do
        {
          v36 = schedule_timeout(v35);
          prepare_to_wait_event(a1 + 3104, &s2, 2);
          if ( (*(_BYTE *)(a1 + 3640) & (v36 == 0)) != 0 )
            v35 = 1;
          else
            v35 = v36;
        }
        while ( (*(_BYTE *)(a1 + 3640) & 1) == 0 && v35 );
        v37 = v35;
        finish_wait(a1 + 3104, &s2);
        if ( !v37 )
          goto LABEL_21;
      }
    }
  }
  if ( !*(_QWORD *)(a1 - 56) )
  {
    mutex_lock(v1);
    lt9611uxc_ctl_en(v3);
    lt9611uxc_edid_en(v3);
    v4 = *(_QWORD *)(a1 + 2784);
    *(_QWORD *)(a1 + 3376) = 0;
    *(_QWORD *)(a1 + 3368) = 0;
    v5 = (_QWORD *)(a1 + 3384);
    *(_QWORD *)(a1 + 3360) = 0;
    *(_QWORD *)(a1 + 3352) = 0;
    *(_QWORD *)(a1 + 3344) = 0;
    *(_QWORD *)(a1 + 3336) = 0;
    *(_QWORD *)(a1 + 3328) = 0;
    *(_QWORD *)(a1 + 3320) = 0;
    *(_QWORD *)(a1 + 3312) = 0;
    *(_QWORD *)(a1 + 3304) = 0;
    *(_QWORD *)(a1 + 3296) = 0;
    *(_QWORD *)(a1 + 3288) = 0;
    *(_QWORD *)(a1 + 3280) = 0;
    *(_QWORD *)(a1 + 3272) = 0;
    *(_QWORD *)(a1 + 3264) = 0;
    *(_QWORD *)(a1 + 3256) = 0;
    *(_QWORD *)(a1 + 3248) = 0;
    *(_QWORD *)(a1 + 3240) = 0;
    *(_QWORD *)(a1 + 3232) = 0;
    *(_QWORD *)(a1 + 3224) = 0;
    *(_QWORD *)(a1 + 3216) = 0;
    *(_QWORD *)(a1 + 3208) = 0;
    *(_QWORD *)(a1 + 3200) = 0;
    *(_QWORD *)(a1 + 3192) = 0;
    *(_QWORD *)(a1 + 3184) = 0;
    *(_QWORD *)(a1 + 3176) = 0;
    *(_QWORD *)(a1 + 3168) = 0;
    *(_QWORD *)(a1 + 3160) = 0;
    *(_QWORD *)(a1 + 3152) = 0;
    *(_QWORD *)(a1 + 3144) = 0;
    *(_QWORD *)(a1 + 3136) = 0;
    *(_QWORD *)(a1 + 3128) = 0;
    v6 = *(_WORD *)(v4 + 2);
    *(_QWORD *)(a1 + 3384) = 0;
    *(_QWORD *)(a1 + 3392) = 0;
    LOWORD(s2) = v6;
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
    v7 = *(_QWORD *)(v4 + 24);
    *(_DWORD *)((char *)&s2 + 2) = 0x20000;
    HIWORD(s2) = 0;
    v39 = a1 + 3384;
    if ( (int)i2c_transfer(v7, &s2, 1) <= 0 )
      printk(&unk_A9C9, "lt9611uxc_write_byte");
    v8 = *(_QWORD *)(a1 + 2784);
    v9 = *(_WORD *)(v8 + 2);
    *v5 = 0;
    *(_QWORD *)(a1 + 3392) = 0;
    *(_QWORD *)(a1 + 3400) = 0;
    *(_QWORD *)(a1 + 3408) = 0;
    LOWORD(s2) = v9;
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
    *(_BYTE *)(a1 + 3384) = 10;
    v10 = *(_QWORD *)(v8 + 24);
    *(_DWORD *)((char *)&s2 + 2) = 0x20000;
    HIWORD(s2) = 0;
    v39 = a1 + 3384;
    if ( (int)i2c_transfer(v10, &s2, 1) <= 0 )
      printk(&unk_A9C9, "lt9611uxc_write_byte");
    lt9611uxc_read(v3, 176, (void *)(a1 + 3128), 0x80u);
    if ( *(_BYTE *)(a1 + 3254) )
    {
      v11 = *(_QWORD *)(a1 + 2784);
      v12 = *(_WORD *)(v11 + 2);
      *(_DWORD *)((char *)&s2 + 2) = 0x20000;
      *v5 = 0;
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
      *(_WORD *)(a1 + 3384) = -32758;
      v13 = *(_QWORD *)(v11 + 24);
      LOWORD(s2) = v12;
      HIWORD(s2) = 0;
      v39 = a1 + 3384;
      if ( (int)i2c_transfer(v13, &s2, 1) <= 0 )
        printk(&unk_A9C9, "lt9611uxc_write_byte");
      lt9611uxc_read(v3, 176, (void *)(a1 + 3256), 0x80u);
    }
    lt9611uxc_ctl_disable(v3);
    mutex_unlock(v1);
    custom = drm_edid_read_custom(a1, lt9611uxc_get_edid_block, v3);
    v15 = drm_edid_raw();
    drm_edid_free(custom);
    if ( v15 )
    {
      *(_QWORD *)(a1 - 56) = kmemdup_noprof(v15, 128, 3264);
      kfree(v15);
    }
  }
LABEL_21:
  if ( *(_QWORD *)(a1 - 56) )
  {
    drm_connector_update_edid_property(a1);
    v16 = drm_add_edid_modes(a1, *(_QWORD *)(a1 - 56));
  }
  else
  {
    v17 = *(_QWORD **)(a1 + 2808);
    if ( v17 != (_QWORD *)(a1 + 2808) )
    {
      while ( 1 )
      {
        v18 = drm_mode_duplicate(*(_QWORD *)a1, v17 - 8);
        if ( !v18 )
          break;
        drm_mode_probed_add(a1, v18);
        v17 = (_QWORD *)*v17;
        if ( v17 == (_QWORD *)(a1 + 2808) )
          goto LABEL_26;
      }
      printk(&unk_B58F, "lt9611uxc_connector_get_modes");
    }
LABEL_26:
    v16 = *(_DWORD *)(a1 + 2800);
  }
  v19 = *(_QWORD *)(a1 - 56);
  s2 = nullptr;
  if ( v19 )
  {
    v22 = *(_QWORD **)(a1 + 200);
    v20 = (_QWORD *)(a1 + 200);
    v21 = v22;
    if ( v22 != v20 )
    {
      v23 = v21 - 8;
      v24 = v21 - 8;
      do
      {
        v21 = (_QWORD *)*v21;
        *((_BYTE *)v23 + 62) &= ~8u;
        if ( v23 != v24 )
        {
          if ( *((unsigned __int16 *)v23 + 7) * *((unsigned __int16 *)v23 + 2) > *((unsigned __int16 *)v24 + 7)
                                                                               * *((unsigned __int16 *)v24 + 2) )
            v24 = v23;
          v25 = drm_mode_vrefresh(v23);
          v26 = drm_mode_vrefresh(v24);
          if ( *((unsigned __int16 *)v23 + 7) * *((unsigned __int16 *)v23 + 2) == *((unsigned __int16 *)v24 + 7)
                                                                                * *((unsigned __int16 *)v24 + 2) )
          {
            v27 = v25 - 60;
            if ( v25 - 60 < 0 )
              v27 = 60 - v25;
            v28 = 60 - v26;
            if ( v26 - 60 >= 0 )
              v28 = v26 - 60;
            if ( v25 < 61 && v27 < v28 )
              v24 = v23;
          }
        }
        v23 = v21 - 8;
      }
      while ( v21 != v20 );
      goto LABEL_48;
    }
  }
  else
  {
    v30 = (__int64 *)(a1 + 200);
    if ( (unsigned int)of_property_read_string(*(_QWORD *)(*v3 + 744LL), "lt,preferred-mode", &s2) )
    {
      v31 = nullptr;
      v32 = v30;
      do
      {
        v32 = (__int64 *)*v32;
        v24 = v31;
        v31 = v32 - 8;
      }
      while ( v32 != v30 );
LABEL_48:
      *((_BYTE *)v24 + 62) |= 8u;
      goto LABEL_49;
    }
    for ( i = (__int64 *)*v30; i != v30; i = (__int64 *)*i )
    {
      if ( !strcmp((const char *)i + 16, s2) )
        *((_BYTE *)i - 2) |= 8u;
    }
  }
LABEL_49:
  _ReadStatusReg(SP_EL0);
  return v16;
}
