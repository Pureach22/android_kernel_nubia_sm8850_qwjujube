__int64 __fastcall cam_icp_hw_mgr_mini_dump_cb(__int64 a1, unsigned __int64 a2, unsigned int *a3)
{
  __int64 v5; // x6
  const char *v6; // x5
  __int64 v7; // x4
  __int64 v8; // x26
  size_t v9; // x0
  size_t v10; // x2
  unsigned int v11; // w8
  size_t v12; // x2
  __int64 v13; // x28
  __int64 v14; // x21
  unsigned __int64 v15; // x8
  __int64 *v16; // x27
  __int64 v17; // x24
  size_t v18; // x0
  size_t v19; // x2
  _QWORD *v20; // x8
  __int64 v21; // x9
  __int64 v22; // x10
  __int64 v23; // x8
  size_t v24; // x2
  __int64 v25; // x23
  void (__fastcall *v26)(__int64, __int64 *); // x8
  __int64 v27; // x0
  __int64 v28; // x23
  __int64 v29; // x9
  unsigned int (__fastcall *v30)(__int64, __int64, __int64 *, __int64); // x11
  __int64 v31; // x0
  __int64 v33; // x22
  __int64 v34; // x0
  __int64 v35; // [xsp+8h] [xbp-38h] BYREF
  unsigned __int64 v36; // [xsp+10h] [xbp-30h]
  __int64 v37; // [xsp+18h] [xbp-28h]
  __int64 v38; // [xsp+20h] [xbp-20h] BYREF
  unsigned __int64 v39; // [xsp+28h] [xbp-18h]
  __int64 v40; // [xsp+30h] [xbp-10h]
  __int64 v41; // [xsp+38h] [xbp-8h]

  v41 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v39 = 0;
  v40 = 0;
  v37 = 0;
  v38 = 0;
  v35 = 0;
  v36 = 0;
  if ( !a1 || a2 <= 0x8C07 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      256,
      1,
      "cam_icp_hw_mgr_mini_dump_cb",
      5230,
      "Invalid params dst %pk len %lu",
      (const void *)a1,
      a2);
LABEL_36:
    v14 = 0;
LABEL_37:
    _ReadStatusReg(SP_EL0);
    return v14;
  }
  v5 = *a3;
  if ( (unsigned int)v5 >= 2 )
  {
    v6 = "Invalid index to hw mgr: %u";
    v7 = 5236;
LABEL_35:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      256,
      1,
      "cam_icp_hw_mgr_mini_dump_cb",
      v7,
      v6);
    goto LABEL_36;
  }
  v8 = g_icp_hw_mgr[v5];
  if ( !v8 )
  {
    v6 = "Uninitialized hw mgr for subdev: %u";
    v7 = 5242;
    goto LABEL_35;
  }
  *(_DWORD *)(a1 + 35828) = 0;
  cam_hfi_mini_dump(*(_DWORD *)(v8 + 156), (void *)(a1 + 464));
  v9 = strnlen((const char *)a1, 0x20u);
  v10 = v9;
  if ( v9 >= 0x21 )
  {
LABEL_41:
    _fortify_panic(2, 32, v10 + 1);
  }
  else if ( v9 != 32 )
  {
    memcpy((void *)a1, (const void *)(v8 + 112), v9);
    memcpy((void *)(a1 + 33240), (const void *)(v8 + 168), 0x338u);
    v11 = *(_DWORD *)(v8 + 64);
    v12 = 584LL * v11;
    if ( v11 >= 4 && (cam_icp_hw_mgr_mini_dump_cb___already_done_670 & 1) == 0 )
    {
      cam_icp_hw_mgr_mini_dump_cb___already_done_670 = 1;
      v33 = 584LL * v11;
      _warn_printk(
        "memcpy: detected field-spanning write (size %zu) of single %s (size %zu)\n",
        v12,
        "field \"&md->dev_info\" at ../vendor/qcom/opensource/camera-kernel/drivers/cam_icp/icp_hw/icp_hw_mgr/cam_icp_hw_mgr.c:5253",
        0x6D8u);
      v12 = v33;
      __break(0x800u);
    }
    memcpy((void *)(a1 + 34064), *(const void **)(v8 + 56), v12);
    v13 = 0;
    v14 = 35848;
    *(_DWORD *)(a1 + 35832) = *(_DWORD *)(v8 + 64);
    *(_DWORD *)(a1 + 35824) = *(_DWORD *)(v8 + 44148);
    *(_BYTE *)(a1 + 35836) = *(_BYTE *)(v8 + 44228);
    *(_BYTE *)(a1 + 35837) = *(_BYTE *)(v8 + 44229);
    *(_BYTE *)(a1 + 35838) = *(_BYTE *)(v8 + 44234);
    *(_BYTE *)(a1 + 35839) = *(_BYTE *)(v8 + 44230);
    v15 = a2 - 35848;
    *(_BYTE *)(a1 + 35841) = *(_BYTE *)(v8 + 44232);
    do
    {
      v16 = *(__int64 **)(*(_QWORD *)(v8 + 96) + v13);
      if ( v16 && *((_DWORD *)v16 + 26) != 3 )
      {
        if ( v15 < 0xEC0 )
          goto LABEL_37;
        v17 = a1 + v14;
        ++*(_DWORD *)(a1 + 35828);
        *(_QWORD *)(a1 + 32 + v13) = a1 + v14;
        *(_BYTE *)(v17 + 3768) = *((_DWORD *)v16 + 26);
        *(_BYTE *)(v17 + 3769) = *((_DWORD *)v16 + 7306);
        v18 = strnlen((const char *)v16 + 29824, 0x80u);
        v19 = v18;
        if ( v18 >= 0x81 )
          goto LABEL_40;
        if ( v18 == 128 )
        {
          _fortify_panic(4, 128, 129);
LABEL_40:
          _fortify_panic(2, 128, v19 + 1);
          goto LABEL_41;
        }
        memcpy((void *)(v17 + 3640), v16 + 3728, v18);
        if ( v16[10] )
        {
          *(_DWORD *)(v17 + 388) = *((_DWORD *)v16 + 22);
          *(_BYTE *)(v17 + 387) = *(_DWORD *)(v16[10] + 16);
          *(_BYTE *)(v17 + 386) = *(_DWORD *)(v16[10] + 4);
          *(_WORD *)(v17 + 384) = *(_DWORD *)(v16[10] + 48);
          v20 = (_QWORD *)v16[10];
          v22 = v20[4];
          v21 = v20[5];
          *(_QWORD *)v17 = v20[3];
          *(_QWORD *)(v17 + 8) = v22;
          *(_QWORD *)(v17 + 16) = v21;
          v23 = *(unsigned int *)(v16[10] + 48);
          v24 = 24 * v23;
          if ( (unsigned int)v23 >= 0x10 && (cam_icp_hw_mgr_mini_dump_cb___already_done_676 & 1) == 0 )
          {
            v28 = 24 * v23;
            cam_icp_hw_mgr_mini_dump_cb___already_done_676 = 1;
            _warn_printk(
              "memcpy: detected field-spanning write (size %zu) of single %s (size %zu)\n",
              v24,
              "field \"ctx_md->acquire.out_res\" at ../vendor/qcom/opensource/camera-kernel/drivers/cam_icp/icp_hw/icp_hw"
              "_mgr/cam_icp_hw_mgr.c:5294",
              0x168u);
            v24 = v28;
            __break(0x800u);
          }
          memcpy((void *)(v17 + 24), (const void *)(v16[10] + 52), v24);
        }
        else
        {
          memset((void *)(a1 + v14), 0, 0x188u);
        }
        memcpy((void *)(v17 + 392), v16 + 223, 0x140u);
        memcpy((void *)(v17 + 3112), v16 + 563, 0xA0u);
        memcpy((void *)(v17 + 3272), v16 + 3608, 0x140u);
        memcpy((void *)(v17 + 712), v16 + 263, 0xA0u);
        memcpy((void *)(v17 + 872), v16 + 283, 0x8C0u);
        *(_BYTE *)(v17 + 3592) = *((_BYTE *)v16 + 4824);
        *(_BYTE *)(v17 + 3593) = *((_BYTE *)v16 + 4825);
        *(_BYTE *)(v17 + 3594) = *((_BYTE *)v16 + 4826);
        *(_BYTE *)(v17 + 3595) = *((_BYTE *)v16 + 4827);
        *(_BYTE *)(v17 + 3596) = *((_BYTE *)v16 + 4828);
        *(_BYTE *)(v17 + 3597) = *((_BYTE *)v16 + 4829);
        *(_BYTE *)(v17 + 3598) = *((_BYTE *)v16 + 4830);
        *(_BYTE *)(v17 + 3599) = *((_BYTE *)v16 + 4831);
        *(_BYTE *)(v17 + 3600) = *((_BYTE *)v16 + 4832);
        *(_BYTE *)(v17 + 3601) = *((_BYTE *)v16 + 4833);
        *(_BYTE *)(v17 + 3602) = *((_BYTE *)v16 + 4834);
        *(_BYTE *)(v17 + 3603) = *((_BYTE *)v16 + 4835);
        *(_BYTE *)(v17 + 3604) = *((_BYTE *)v16 + 4836);
        *(_BYTE *)(v17 + 3605) = *((_BYTE *)v16 + 4837);
        *(_BYTE *)(v17 + 3606) = *((_BYTE *)v16 + 4838);
        *(_BYTE *)(v17 + 3607) = *((_BYTE *)v16 + 4839);
        *(_BYTE *)(v17 + 3608) = *((_BYTE *)v16 + 4840);
        *(_BYTE *)(v17 + 3609) = *((_BYTE *)v16 + 4841);
        *(_BYTE *)(v17 + 3610) = *((_BYTE *)v16 + 4842);
        *(_BYTE *)(v17 + 3611) = *((_BYTE *)v16 + 4843);
        *(_BYTE *)(v17 + 3612) = *((_BYTE *)v16 + 4844);
        *(_BYTE *)(v17 + 3613) = *((_BYTE *)v16 + 4845);
        *(_BYTE *)(v17 + 3614) = *((_BYTE *)v16 + 4846);
        *(_BYTE *)(v17 + 3615) = *((_BYTE *)v16 + 4847);
        *(_BYTE *)(v17 + 3616) = *((_BYTE *)v16 + 4848);
        *(_BYTE *)(v17 + 3617) = *((_BYTE *)v16 + 4849);
        *(_BYTE *)(v17 + 3618) = *((_BYTE *)v16 + 4850);
        *(_BYTE *)(v17 + 3619) = *((_BYTE *)v16 + 4851);
        *(_BYTE *)(v17 + 3620) = *((_BYTE *)v16 + 4852);
        *(_BYTE *)(v17 + 3621) = *((_BYTE *)v16 + 4853);
        *(_BYTE *)(v17 + 3622) = *((_BYTE *)v16 + 4854);
        *(_BYTE *)(v17 + 3623) = *((_BYTE *)v16 + 4855);
        *(_BYTE *)(v17 + 3624) = *((_BYTE *)v16 + 4856);
        *(_BYTE *)(v17 + 3625) = *((_BYTE *)v16 + 4857);
        *(_BYTE *)(v17 + 3626) = *((_BYTE *)v16 + 4858);
        *(_BYTE *)(v17 + 3627) = *((_BYTE *)v16 + 4859);
        *(_BYTE *)(v17 + 3628) = *((_BYTE *)v16 + 4860);
        *(_BYTE *)(v17 + 3629) = *((_BYTE *)v16 + 4861);
        *(_BYTE *)(v17 + 3630) = *((_BYTE *)v16 + 4862);
        v25 = v14 + 3776;
        *(_BYTE *)(v17 + 3631) = *((_BYTE *)v16 + 4863);
        v39 = a2 - (v14 + 3776);
        v40 = 0;
        v38 = a1 + v14 + 3776;
        v26 = *(void (__fastcall **)(__int64, __int64 *))(v8 + 104);
        v27 = *v16;
        if ( *((_DWORD *)v26 - 1) != -72220 )
          __break(0x8228u);
        v26(v27, &v38);
        v14 = v40 + v25;
        v15 = a2 - (v40 + v25);
        if ( a2 <= v40 + v25 )
        {
          v14 = v25;
          goto LABEL_37;
        }
        *(_QWORD *)(v17 + 3632) = v38;
      }
      v13 += 8;
    }
    while ( v13 != 432 );
    if ( (*(_BYTE *)(v8 + 44232) & 1) == 0 )
    {
      v29 = *(_QWORD *)(v8 + 80);
      v36 = v15;
      v37 = 0;
      v30 = *(unsigned int (__fastcall **)(__int64, __int64, __int64 *, __int64))(v29 + 88);
      v31 = *(_QWORD *)(v29 + 112);
      v35 = a1 + v14;
      if ( *((_DWORD *)v30 - 1) != -1055839300 )
        __break(0x822Bu);
      if ( !v30(v31, 14, &v35, 24) )
      {
        v14 += v37;
        *(_QWORD *)(a1 + 35816) = v35;
      }
    }
    goto LABEL_37;
  }
  v34 = _fortify_panic(4, 32, 33);
  return cam_icp_get_svs_clk_info(v34);
}
