__int64 __fastcall cam_icp_allocate_shared_mem(__int64 a1)
{
  int v2; // w0
  unsigned int v3; // w0
  unsigned int v4; // w20
  const char *v5; // x5
  __int64 v6; // x6
  __int64 v7; // x4
  int v8; // w9
  int v9; // w0
  __int64 v10; // x9
  __int64 v11; // x10
  __int64 v12; // x12
  int v13; // w13
  int v14; // w14
  __int64 v15; // x8
  __int64 v16; // x9
  __int64 v17; // x8
  __int64 v18; // x9
  __int64 v19; // x8
  __int64 v20; // x10
  __int64 v21; // x9
  unsigned __int64 v22; // x10
  unsigned __int64 v23; // x8
  __int64 v24; // x11
  __int64 v25; // x9
  __int64 v26; // x10
  __int64 v27; // x10
  int v28; // w0
  int v29; // w0
  int v30; // w0
  __int64 v32; // [xsp+8h] [xbp-88h] BYREF
  __int64 v33; // [xsp+10h] [xbp-80h]
  __int64 v34; // [xsp+18h] [xbp-78h]
  unsigned __int64 v35; // [xsp+20h] [xbp-70h]
  __int64 v36; // [xsp+28h] [xbp-68h]
  _QWORD v37[2]; // [xsp+30h] [xbp-60h] BYREF
  int v38; // [xsp+40h] [xbp-50h]
  int v39; // [xsp+44h] [xbp-4Ch]
  __int64 v40; // [xsp+48h] [xbp-48h] BYREF
  __int64 v41; // [xsp+50h] [xbp-40h]
  __int64 v42; // [xsp+58h] [xbp-38h]
  __int64 v43; // [xsp+60h] [xbp-30h]
  __int64 v44; // [xsp+68h] [xbp-28h]
  __int64 v45; // [xsp+70h] [xbp-20h]
  __int64 v46; // [xsp+78h] [xbp-18h]
  __int64 v47; // [xsp+80h] [xbp-10h]
  __int64 v48; // [xsp+88h] [xbp-8h]

  v48 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_DWORD *)(a1 + 148);
  v46 = 0;
  v47 = 0;
  v44 = 0;
  v45 = 0;
  v42 = 0;
  v43 = 0;
  v40 = 0;
  v41 = 0;
  if ( (unsigned int)cam_smmu_get_region_info(v2, 6, &v40) )
  {
    v3 = cam_icp_alloc_shared_mem(a1, 0x2000, a1 + 168);
    if ( !v3 )
    {
      v9 = cam_icp_alloc_shared_mem(a1, 12288, a1 + 208);
      if ( v9 )
      {
        v4 = v9;
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          256,
          1,
          "cam_icp_allocate_shared_mem",
          4147,
          "[%s] Unable to allocate cmd q memory rc %d",
          (const char *)(a1 + 112),
          v9);
      }
      else
      {
        v28 = cam_icp_alloc_shared_mem(a1, 12288, a1 + 248);
        if ( v28 )
        {
          v4 = v28;
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            256,
            1,
            "cam_icp_allocate_shared_mem",
            4154,
            "[%s] Unable to allocate msg q memory rc %d",
            (const char *)(a1 + 112),
            v28);
        }
        else
        {
          v29 = cam_icp_alloc_shared_mem(a1, 106496, a1 + 288);
          if ( v29 )
          {
            v4 = v29;
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              256,
              1,
              "cam_icp_allocate_shared_mem",
              4161,
              "[%s] Unable to allocate dbg q memory rc %d",
              (const char *)(a1 + 112),
              v29);
          }
          else
          {
            v30 = cam_icp_alloc_shared_mem(a1, 0x2000, a1 + 448);
            if ( v30 )
            {
              v4 = v30;
              ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                3,
                256,
                1,
                "cam_icp_allocate_shared_mem",
                4168,
                "[%s] Unable to allocate sfr buffer rc %d",
                (const char *)(a1 + 112),
                v30);
            }
            else
            {
              v4 = cam_icp_alloc_secheap_mem(a1, a1 + 328);
              if ( !v4 )
                goto LABEL_24;
              ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                3,
                256,
                1,
                "cam_icp_allocate_shared_mem",
                4175,
                "[%s] Unable to allocate sec heap memory rc %d",
                (const char *)(a1 + 112),
                v4);
              cam_mem_mgr_release_mem((_DWORD *)(a1 + 448));
            }
            cam_mem_mgr_release_mem((_DWORD *)(a1 + 288));
          }
          cam_mem_mgr_release_mem((_DWORD *)(a1 + 248));
        }
        cam_mem_mgr_release_mem((_DWORD *)(a1 + 208));
      }
      cam_mem_mgr_release_mem((_DWORD *)(a1 + 168));
      goto LABEL_24;
    }
    v4 = v3;
    v5 = "[%s] Unable to allocate qtbl memory, rc %d";
    v6 = a1 + 112;
    v7 = 4140;
    goto LABEL_6;
  }
  v8 = *(_DWORD *)(a1 + 148);
  v35 = 0;
  v36 = 0;
  v33 = 0;
  v34 = 0;
  v32 = 0;
  v37[0] = 1200128;
  v37[1] = 0;
  v38 = v8;
  v39 = 8;
  v4 = ((__int64 (__fastcall *)(_QWORD *, __int64, __int64 *))cam_mem_mgr_reserve_memory_region)(v37, 6, &v32);
  if ( v4 )
  {
    v5 = "[%s] Unable to reserve fw uncached memory rc %d";
    v6 = a1 + 112;
    v7 = 4067;
LABEL_6:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64, _QWORD))cam_print_log)(
      3,
      256,
      1,
      "cam_icp_allocate_shared_mem",
      v7,
      v5,
      v6,
      v4);
    goto LABEL_24;
  }
  v10 = v44;
  v11 = v45;
  *(_BYTE *)(a1 + 984) = 1;
  v12 = v32;
  v13 = v34;
  v14 = v36;
  *(_QWORD *)(a1 + 232) = 12288;
  *(_QWORD *)(a1 + 888) = v10;
  v15 = v46;
  v16 = v47;
  *(_QWORD *)(a1 + 896) = v11;
  *(_QWORD *)(a1 + 328) = v12;
  *(_QWORD *)(a1 + 904) = v15;
  *(_QWORD *)(a1 + 912) = v16;
  v17 = v40;
  v18 = v41;
  *(_DWORD *)(a1 + 344) = v13;
  *(_DWORD *)(a1 + 360) = v14;
  *(_QWORD *)(a1 + 856) = v17;
  v19 = v42;
  v20 = v43;
  *(_QWORD *)(a1 + 864) = v18;
  *(_DWORD *)(a1 + 184) = v13;
  *(_QWORD *)(a1 + 880) = v20;
  v21 = v34;
  v22 = v35;
  *(_QWORD *)(a1 + 872) = v19;
  v23 = v35;
  v24 = v36;
  *(_DWORD *)(a1 + 200) = v14;
  *(_QWORD *)(a1 + 504) = v21;
  *(_QWORD *)(a1 + 512) = v22;
  v26 = v32;
  v25 = v33;
  *(_QWORD *)(a1 + 520) = v24;
  *(_DWORD *)(a1 + 224) = v13;
  *(_QWORD *)(a1 + 488) = v26;
  *(_QWORD *)(a1 + 496) = v25;
  LODWORD(v24) = v33;
  LODWORD(v25) = HIDWORD(v33);
  *(_QWORD *)(a1 + 352) = 1052672;
  v27 = v12 + 1052672;
  v12 += 106496;
  *(_QWORD *)(a1 + 168) = v27;
  *(_DWORD *)(a1 + 336) = v24;
  LODWORD(v24) = v24 + 1052672;
  *(_QWORD *)(a1 + 208) = v12 + 954368;
  *(_DWORD *)(a1 + 256) = v24 + 20480;
  *(_QWORD *)(a1 + 248) = v12 + 966656;
  *(_DWORD *)(a1 + 176) = v24;
  *(_DWORD *)(a1 + 180) = v25;
  *(_DWORD *)(a1 + 216) = v24 + 0x2000;
  *(_DWORD *)(a1 + 220) = v25;
  *(_DWORD *)(a1 + 296) = v24 + 0x8000;
  *(_DWORD *)(a1 + 456) = v24 + 139264;
  *(_DWORD *)(a1 + 340) = v25;
  *(_QWORD *)(a1 + 192) = 0x2000;
  *(_DWORD *)(a1 + 240) = v14;
  *(_QWORD *)(a1 + 272) = 12288;
  *(_DWORD *)(a1 + 260) = v25;
  *(_DWORD *)(a1 + 264) = v13;
  *(_DWORD *)(a1 + 280) = v14;
  *(_QWORD *)(a1 + 288) = v12 + 978944;
  *(_QWORD *)(a1 + 312) = 106496;
  *(_DWORD *)(a1 + 300) = v25;
  *(_DWORD *)(a1 + 304) = v13;
  *(_DWORD *)(a1 + 320) = v14;
  *(_QWORD *)(a1 + 448) = v12 + 1085440;
  *(_QWORD *)(a1 + 472) = 0x2000;
  *(_DWORD *)(a1 + 460) = v25;
  *(_DWORD *)(a1 + 464) = v13;
  *(_DWORD *)(a1 + 480) = v14;
  if ( v23 >= 0x125000 )
  {
    v4 = 0;
  }
  else
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      256,
      1,
      "cam_icp_allocate_shared_mem",
      4132,
      "[%s] FW uncached region size %lld not enough, required %lld",
      (const char *)(a1 + 112),
      1200128,
      v23);
    cam_mem_mgr_free_memory_region((unsigned int *)(a1 + 488));
  }
LABEL_24:
  _ReadStatusReg(SP_EL0);
  return v4;
}
