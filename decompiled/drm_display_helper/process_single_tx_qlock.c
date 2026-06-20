__int64 __fastcall process_single_tx_qlock(__int64 a1, __int64 a2, char a3)
{
  int v3; // w8
  char v7; // w8
  __int64 v8; // x24
  char v9; // w25
  int v10; // w9
  char v11; // w8
  unsigned int v12; // w23
  char v13; // w9
  unsigned int v14; // w21
  void *v15; // x0
  int v16; // w8
  int v17; // w9
  __int64 v18; // x21
  int v19; // w24
  unsigned int v20; // w8
  int v21; // w12
  unsigned __int8 v22; // w10
  char *v23; // x9
  __int64 v24; // x25
  int v25; // w1
  char v26; // w11
  int v27; // w17
  int v28; // w2
  unsigned int v29; // w3
  unsigned int v30; // w3
  char v32; // w10
  __int64 v33; // x2
  char v34; // w10
  char v35; // w10
  char v36; // w10
  __int64 v37; // x1
  char v38; // w0
  int v39; // w23
  int v40; // w27
  int v41; // w24
  int v42; // w28
  int v43; // w8
  int v44; // w22
  int v45; // w0
  int v46; // w5
  int v47; // w22
  int v48; // w27
  int v49; // w8
  int v50; // w28
  int v51; // w0
  int v52; // w22
  int v53; // w27
  int v54; // w8
  int v55; // w28
  int v56; // w0
  int v57; // w22
  int v58; // w27
  int v59; // w8
  int v60; // w28
  int v61; // w0
  int v62; // w22
  int v63; // w27
  int v64; // w8
  int v65; // w28
  int v66; // w0
  int v67; // w22
  int v68; // w8
  int v69; // w27
  int v70; // w0
  bool v71; // zf
  __int64 result; // x0
  __int64 v73; // x8
  __int64 v74; // x1
  __int64 v75; // x0
  _QWORD v76[6]; // [xsp+8h] [xbp-78h] BYREF
  _QWORD dest[2]; // [xsp+38h] [xbp-48h] BYREF
  __int64 v78; // [xsp+48h] [xbp-38h] BYREF
  __int64 v79; // [xsp+50h] [xbp-30h]
  __int64 v80; // [xsp+58h] [xbp-28h]
  __int64 v81; // [xsp+60h] [xbp-20h]
  __int64 v82; // [xsp+68h] [xbp-18h]
  __int64 v83; // [xsp+70h] [xbp-10h]
  __int64 v84; // [xsp+78h] [xbp-8h]

  v84 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(_DWORD *)(a2 + 340);
  if ( v3 == 2 )
  {
LABEL_123:
    result = 0;
LABEL_131:
    _ReadStatusReg(SP_EL0);
    return result;
  }
  *(_QWORD *)((char *)dest + 6) = 0;
  dest[0] = 0;
  if ( !v3 )
    *(_DWORD *)(a2 + 340) = 1;
  v7 = *(_BYTE *)a2;
  v8 = *(_QWORD *)(a2 + 312);
  v9 = 6;
  v82 = 0;
  v83 = 0;
  v10 = v7 & 0x7F;
  v11 = 1;
  v80 = 0;
  v81 = 0;
  v78 = 0;
  v79 = 0;
  if ( v10 == 2 )
  {
    v12 = 1;
  }
  else
  {
    v12 = 1;
    if ( (unsigned int)(v10 - 19) >= 2 )
    {
      v12 = *(unsigned __int8 *)(v8 + 32);
      v11 = 0;
      v9 = v12 - 1;
    }
  }
  v13 = *(_BYTE *)(a2 + 344);
  v14 = v12 >> 1;
  LOBYTE(dest[1]) = v11;
  BYTE1(dest[1]) = v13;
  if ( v12 >= 0x1E )
  {
    _fortify_panic(17, 14, v12 >> 1);
LABEL_134:
    v15 = (void *)_fortify_panic(17, v37, v33);
    goto LABEL_135;
  }
  if ( v12 >= 0x12 && (set_hdr_from_dst_qlock___already_done & 1) == 0 )
  {
    set_hdr_from_dst_qlock___already_done = 1;
    _warn_printk(
      "memcpy: detected field-spanning write (size %zu) of single %s (size %zu)\n",
      v12 >> 1,
      "field \"hdr->rad\" at ../soc-repo/drivers/gpu/drm/display/drm_dp_mst_topology.c:2783",
      8u);
    __break(0x800u);
  }
  v15 = memcpy(dest, (const void *)(v8 + 24), v12 >> 1);
  v16 = *(unsigned __int8 *)(a2 + 305) - *(unsigned __int8 *)(a2 + 304);
  v17 = (unsigned __int8)(44 - v14);
  if ( v16 >= v17 )
    v18 = (unsigned __int8)(44 - v14);
  else
    v18 = (unsigned int)v16;
  if ( *(_BYTE *)(a2 + 304) )
  {
    if ( v16 > v17 )
      goto LABEL_18;
    goto LABEL_17;
  }
  BYTE3(dest[1]) = 1;
  if ( v16 <= v17 )
LABEL_17:
    BYTE4(dest[1]) = 1;
LABEL_18:
  v19 = v18 + 1;
  BYTE2(dest[1]) = v18 + 1;
  LOBYTE(v78) = v9 & 0xF | (16 * v12);
  if ( v12 < 2 )
  {
    v20 = 1;
LABEL_38:
    v21 = 0;
    v22 = 0;
    v23 = (char *)&v78 + v20;
    v24 = v20 + 2;
    v25 = 7;
    v26 = (BYTE4(dest[1]) << 6) | (BYTE3(dest[1]) << 7) | (16 * BYTE5(dest[1]));
    *v23 = v19 & 0x3F | (LOBYTE(dest[1]) << 7) | (BYTE1(dest[1]) << 6);
    v27 = -12 - 8 * v20;
    LOBYTE(v28) = 0x80;
    v23[1] = v26;
    do
    {
      if ( v22 > 0x2Fu )
        goto LABEL_132;
      v29 = (unsigned __int8)(v28 & *((_BYTE *)&v78 + v22));
      v28 = (unsigned __int8)v28 >> 1;
      v30 = v29 >> v25--;
      if ( !v28 )
      {
        ++v22;
        LOBYTE(v28) = 0x80;
        v25 = 7;
      }
      v21 = v30 | (2 * v21);
      if ( (v21 & 0x10) != 0 )
        v21 ^= 0x13u;
    }
    while ( !__CFADD__(v27++, 1) );
    v32 = 2 * v21;
    v33 = (int)v18;
    if ( (v21 & 8) != 0 )
      v32 = (2 * v21) ^ 0x13;
    if ( (v32 & 8) != 0 )
      v34 = (2 * v32) ^ 0x13;
    else
      v34 = 2 * v32;
    if ( (v34 & 8) != 0 )
      v35 = (2 * v34) ^ 0x13;
    else
      v35 = 2 * v34;
    if ( (v35 & 8) != 0 )
      v36 = (2 * v35) ^ 3;
    else
      v36 = 2 * v35;
    v37 = 46 - v20;
    v23[1] = v36 & 0xF | v26;
    if ( (unsigned int)v37 >= (unsigned int)v18 )
    {
      memcpy((char *)&v78 + v24, (const void *)(a2 + *(unsigned __int8 *)(a2 + 304)), (int)v18);
      v38 = drm_dp_msg_data_crc4((char *)&v78 + v24);
      if ( (unsigned __int64)(v24 + v18) > 0x2F )
LABEL_132:
        __break(1u);
      *((_BYTE *)&v78 + v24 + v18) = v38;
      v39 = v24 + v19;
      v40 = 0;
      if ( (a3 & 1) != 0 )
        v41 = 4608;
      else
        v41 = 4096;
      v42 = v39;
      do
      {
        v43 = *(_DWORD *)(a1 + 120);
        if ( v42 < v43 )
          v43 = v42;
        if ( v43 >= 16 )
          v44 = 16;
        else
          v44 = v43;
        v45 = drm_dp_dpcd_write(*(_QWORD **)(a1 + 128), v40 + v41, (__int64)&v78 + v40, v44);
        v46 = v45;
        if ( v44 != v45 )
        {
          if ( v45 == -5 )
          {
            v47 = 0;
            v48 = v39;
            while ( 1 )
            {
              v49 = *(_DWORD *)(a1 + 120);
              if ( v48 < v49 )
                v49 = v48;
              v50 = v49 >= 16 ? 16 : v49;
              v51 = drm_dp_dpcd_write(*(_QWORD **)(a1 + 128), v47 + v41, (__int64)&v78 + v47, v50);
              if ( v50 != v51 )
                break;
              v48 -= v50;
              v47 += v50;
              if ( v48 <= 0 )
                goto LABEL_120;
            }
            v44 = v50;
            v46 = v51;
            if ( v51 == -5 )
            {
              v52 = 0;
              v53 = v39;
              while ( 1 )
              {
                v54 = *(_DWORD *)(a1 + 120);
                if ( v53 < v54 )
                  v54 = v53;
                v55 = v54 >= 16 ? 16 : v54;
                v56 = drm_dp_dpcd_write(*(_QWORD **)(a1 + 128), v52 + v41, (__int64)&v78 + v52, v55);
                if ( v55 != v56 )
                  break;
                v53 -= v55;
                v52 += v55;
                if ( v53 <= 0 )
                  goto LABEL_120;
              }
              v44 = v55;
              v46 = v56;
              if ( v56 == -5 )
              {
                v57 = 0;
                v58 = v39;
                while ( 1 )
                {
                  v59 = *(_DWORD *)(a1 + 120);
                  if ( v58 < v59 )
                    v59 = v58;
                  v60 = v59 >= 16 ? 16 : v59;
                  v61 = drm_dp_dpcd_write(*(_QWORD **)(a1 + 128), v57 + v41, (__int64)&v78 + v57, v60);
                  if ( v60 != v61 )
                    break;
                  v58 -= v60;
                  v57 += v60;
                  if ( v58 <= 0 )
                    goto LABEL_120;
                }
                v44 = v60;
                v46 = v61;
                if ( v61 == -5 )
                {
                  v62 = 0;
                  v63 = v39;
                  while ( 1 )
                  {
                    v64 = *(_DWORD *)(a1 + 120);
                    if ( v63 < v64 )
                      v64 = v63;
                    v65 = v64 >= 16 ? 16 : v64;
                    v66 = drm_dp_dpcd_write(*(_QWORD **)(a1 + 128), v62 + v41, (__int64)&v78 + v62, v65);
                    if ( v65 != v66 )
                      break;
                    v63 -= v65;
                    v62 += v65;
                    if ( v63 <= 0 )
                      goto LABEL_120;
                  }
                  v44 = v65;
                  v46 = v66;
                  if ( v66 == -5 )
                  {
                    v67 = 0;
                    while ( 1 )
                    {
                      v68 = *(_DWORD *)(a1 + 120);
                      if ( v39 < v68 )
                        v68 = v39;
                      v69 = v68 >= 16 ? 16 : v68;
                      v70 = drm_dp_dpcd_write(*(_QWORD **)(a1 + 128), v67 + v41, (__int64)&v78 + v67, v69);
                      if ( v69 != v70 )
                        break;
                      v39 -= v69;
                      v67 += v69;
                      if ( v39 <= 0 )
                        goto LABEL_120;
                    }
                    v44 = v69;
                    v46 = v70;
                  }
                }
              }
            }
          }
          v73 = *(_QWORD *)(a1 + 104);
          if ( v73 )
            v74 = *(_QWORD *)(v73 + 8);
          else
            v74 = 0;
          _drm_dev_dbg(0, v74, 2, "failed to dpcd write %d %d\n", v44, v46);
          if ( (*(&_drm_debug + 1) & 1) != 0 )
          {
            v75 = *(_QWORD *)(a1 + 104);
            memset(v76, 0, sizeof(v76));
            drm_dbg_printer(v75, v76);
            drm_printf(v76, "sideband msg failed to send\n");
            drm_dp_mst_dump_sideband_msg_tx((__int64)v76, a2);
          }
          result = 4294967291LL;
          goto LABEL_131;
        }
        v42 -= v44;
        v40 += v44;
      }
      while ( v42 > 0 );
LABEL_120:
      v71 = *(unsigned __int8 *)(a2 + 305) == (unsigned __int8)(*(_BYTE *)(a2 + 304) + v18);
      *(_BYTE *)(a2 + 304) += v18;
      if ( !v71 )
        goto LABEL_123;
      result = 1;
      *(_DWORD *)(a2 + 340) = 2;
      goto LABEL_131;
    }
    goto LABEL_134;
  }
  BYTE1(v78) = dest[0];
  if ( v12 <= 3 )
  {
    v20 = 2;
    goto LABEL_38;
  }
  BYTE2(v78) = BYTE1(dest[0]);
  if ( v12 < 6 )
  {
    v20 = 3;
    goto LABEL_38;
  }
  BYTE3(v78) = BYTE2(dest[0]);
  if ( v12 < 8 )
  {
    v20 = 4;
    goto LABEL_38;
  }
  BYTE4(v78) = BYTE3(dest[0]);
  if ( v12 < 0xA )
  {
    v20 = 5;
    goto LABEL_38;
  }
  BYTE5(v78) = BYTE4(dest[0]);
  if ( v12 < 0xC )
  {
    v20 = 6;
    goto LABEL_38;
  }
  BYTE6(v78) = BYTE5(dest[0]);
  if ( v12 < 0xE )
  {
    v20 = 7;
    goto LABEL_38;
  }
  HIBYTE(v78) = BYTE6(dest[0]);
  if ( v12 < 0x10 )
  {
    v20 = 8;
    goto LABEL_38;
  }
  LOBYTE(v79) = HIBYTE(dest[0]);
  if ( v12 <= 0x11 )
  {
    v20 = 9;
    goto LABEL_38;
  }
LABEL_135:
  __break(0x5512u);
  return drm_dp_msg_data_crc4(v15);
}
