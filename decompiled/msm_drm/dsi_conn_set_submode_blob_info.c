__int64 __fastcall dsi_conn_set_submode_blob_info(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  int v5; // w10
  unsigned int v7; // w8
  int v8; // w11
  unsigned int v9; // w9
  int v10; // w12
  int v11; // w9
  int v12; // w10
  unsigned int v14; // w9
  unsigned int v15; // w10
  int v16; // w8
  int v18; // w9
  int v19; // w0
  char v20; // w8
  __int64 v21; // x28
  __int64 v22; // x22
  unsigned int v23; // w27
  __int64 v24; // x23
  __int64 v25; // x25
  __int64 v26; // x26
  int v27; // w8
  __int64 v28; // x2
  __int64 v29; // x2
  __int64 v30; // x0
  __int64 v31; // x8
  unsigned __int64 v32; // x3
  __int64 v33; // x26
  __int64 result; // x0
  unsigned __int64 v35; // [xsp+0h] [xbp-D0h] BYREF
  __int128 v36; // [xsp+8h] [xbp-C8h]
  unsigned __int64 v37; // [xsp+18h] [xbp-B8h]
  __int128 v38; // [xsp+20h] [xbp-B0h]
  __int64 v39; // [xsp+30h] [xbp-A0h]
  __int64 v40; // [xsp+38h] [xbp-98h]
  __int64 v41; // [xsp+40h] [xbp-90h]
  __int64 v42; // [xsp+48h] [xbp-88h]
  __int64 v43; // [xsp+50h] [xbp-80h]
  __int64 v44; // [xsp+58h] [xbp-78h]
  __int64 v45; // [xsp+60h] [xbp-70h]
  __int64 v46; // [xsp+68h] [xbp-68h]
  __int64 v47; // [xsp+70h] [xbp-60h]
  __int64 v48; // [xsp+78h] [xbp-58h]
  __int64 v49; // [xsp+80h] [xbp-50h]
  __int64 v50; // [xsp+88h] [xbp-48h]
  __int64 v51; // [xsp+90h] [xbp-40h]
  __int64 v52; // [xsp+98h] [xbp-38h]
  __int64 v53; // [xsp+A0h] [xbp-30h]
  __int64 v54; // [xsp+A8h] [xbp-28h]
  __int64 v55; // [xsp+B0h] [xbp-20h]
  __int64 v56; // [xsp+B8h] [xbp-18h]
  __int64 v57; // [xsp+C0h] [xbp-10h]

  v57 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v55 = 0;
  v56 = 0;
  v53 = 0;
  v54 = 0;
  v51 = 0;
  v52 = 0;
  v49 = 0;
  v50 = 0;
  v47 = 0;
  v48 = 0;
  v45 = 0;
  v46 = 0;
  v43 = 0;
  v44 = 0;
  v41 = 0;
  v42 = 0;
  v39 = 0;
  v40 = 0;
  v38 = 0u;
  v37 = 0;
  v35 = 0;
  v36 = 0u;
  if ( a1 && a3 && a4 )
  {
    v5 = *(unsigned __int16 *)(a4 + 8);
    v7 = *(unsigned __int16 *)(a4 + 4);
    v8 = *(unsigned __int16 *)(a4 + 6);
    v9 = *(unsigned __int16 *)(a4 + 10) - v5;
    v10 = *(unsigned __int16 *)(a4 + 18);
    *((_QWORD *)&v36 + 1) = 0;
    v37 = 0;
    v35 = __PAIR64__(v9, v7);
    v11 = v5 - v8;
    v12 = *(unsigned __int16 *)(a4 + 20);
    v55 = 0;
    v56 = 0;
    LODWORD(v36) = v11;
    *(_QWORD *)((char *)&v36 + 4) = v8 - v7;
    v14 = v12 - v10;
    v15 = *(unsigned __int16 *)(a4 + 14);
    v16 = *(unsigned __int16 *)(a4 + 12);
    v53 = 0;
    v54 = 0;
    v37 = __PAIR64__(v14, v15);
    v18 = *(unsigned __int16 *)(a4 + 16);
    DWORD2(v36) = v16;
    v51 = 0;
    v52 = 0;
    v49 = 0;
    v50 = 0;
    v47 = 0;
    v48 = 0;
    v45 = 0;
    v46 = 0;
    v43 = 0;
    v44 = 0;
    v41 = 0;
    v42 = 0;
    v39 = 0;
    v40 = 0;
    HIDWORD(v38) = 0;
    LODWORD(v38) = v10 - v18;
    *(_QWORD *)((char *)&v38 + 4) = v18 - v15;
    v19 = drm_mode_vrefresh(a4);
    v20 = *(_BYTE *)(a4 + 24);
    HIDWORD(v38) = v19;
    HIDWORD(v36) = v20 & 1;
    DWORD2(v38) = (v20 & 4) != 0;
    mutex_lock(a3 + 72);
    v21 = *(unsigned int *)(*(_QWORD *)(a3 + 264) + 1436LL);
    if ( (int)v21 >= 1 )
    {
      v22 = 0;
      v23 = -22;
      v24 = 184;
      do
      {
        v25 = *(_QWORD *)(a3 + 824);
        v26 = v25 + v24;
        if ( (dsi_display_mode_match(&v35, v25 + v24 - 184, 3) & 1) != 0 )
        {
          sde_kms_info_add_keyint(a2, (__int64)"submode_idx", v22);
          if ( *(_BYTE *)(v26 - 12) )
            v23 = v22;
          sde_kms_info_add_keyint(a2, (__int64)"panel_mode_capabilities", *(_DWORD *)(v26 - 24) & 3LL);
          v27 = *(_DWORD *)(v26 - 20);
          if ( v27 == 3 )
            v28 = 1;
          else
            v28 = 2LL * (v27 == 7);
          sde_kms_info_add_keyint(a2, (__int64)"bpp_mode", v28);
          if ( *(_BYTE *)(*(_QWORD *)v26 + 3400LL) )
            v29 = 1;
          else
            v29 = 2;
          sde_kms_info_add_keyint(a2, (__int64)"dsc_mode", v29);
          v30 = ((__int64 (__fastcall *)(__int64, _QWORD, _QWORD))sde_conn_get_topology_name)(
                  a1,
                  *(_QWORD *)(*(_QWORD *)v26 + 2480LL),
                  *(_QWORD *)(*(_QWORD *)v26 + 2488LL));
          if ( v30 )
            ((void (__fastcall *)(__int64, const char *, __int64))sde_kms_info_add_keystr)(a2, "topology", v30);
          v31 = *(_QWORD *)(v25 + v24);
          v32 = *(unsigned int *)(v31 + 2424);
          if ( (_DWORD)v32 )
          {
            v33 = *(unsigned int *)(*(_QWORD *)(a3 + 264) + 1396LL);
            sde_kms_info_add_list(a2, "dyn_bitclk_list", *(_QWORD *)(v31 + 2432), v32);
            if ( (unsigned int)v33 >= 5 )
              __break(0x5512u);
            ((void (__fastcall *)(__int64, const char *, char *))sde_kms_info_add_keystr)(
              a2,
              "dyn_fp_type",
              off_290D08[v33]);
            sde_kms_info_add_list(
              a2,
              "dyn_fp_list",
              *(_QWORD *)(*(_QWORD *)(v25 + v24) + 2448LL),
              *(unsigned int *)(*(_QWORD *)(v25 + v24) + 2424LL));
            sde_kms_info_add_list(
              a2,
              "dyn_pclk_list",
              *(_QWORD *)(*(_QWORD *)(v25 + v24) + 2456LL),
              *(unsigned int *)(*(_QWORD *)(v25 + v24) + 2424LL));
          }
        }
        ++v22;
        v24 += 192;
      }
      while ( v21 != v22 );
      if ( (v23 & 0x80000000) == 0 )
        sde_kms_info_add_keyint(a2, (__int64)"preferred_submode_idx", v23);
    }
    result = mutex_unlock(a3 + 72);
  }
  else
  {
    result = drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: Invalid params\n");
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
