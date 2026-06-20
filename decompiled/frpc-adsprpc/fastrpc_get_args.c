__int64 __fastcall fastrpc_get_args(int a1, __int64 a2)
{
  __int64 v3; // x8
  int v4; // w10
  __int64 v5; // x22
  __int64 v6; // x19
  int v7; // w9
  __int64 v8; // x11
  int v9; // w21
  size_t v10; // x23
  _QWORD *v11; // x13
  __int64 v12; // x15
  _QWORD *v13; // x26
  __int64 v14; // x10
  __int64 v15; // x28
  __int64 v16; // x22
  __int64 v17; // x26
  __int64 v18; // x27
  __int64 v19; // x8
  __int64 v20; // x10
  unsigned __int8 v21; // w24
  unsigned int v22; // w25
  int v23; // w25
  int v24; // w19
  unsigned __int64 v25; // x8
  __int64 result; // x0
  int v27; // w8
  int v28; // w9
  __int64 v29; // x22
  __int64 v30; // x27
  __int64 v31; // x25
  _QWORD *v32; // x9
  unsigned __int64 v33; // x8
  __int64 v34; // x28
  _QWORD *v35; // x19
  size_t v36; // x24
  _DWORD *v37; // x8
  __int64 v38; // x8
  int v39; // w10
  __int64 v40; // x25
  _QWORD *v41; // x21
  __int64 v42; // x8
  size_t v43; // x5
  unsigned __int64 v44; // x26
  unsigned __int64 *vma; // x0
  unsigned __int64 v46; // x25
  __int64 v47; // x8
  _QWORD *v48; // x9
  __int64 v49; // x8
  unsigned __int64 v50; // x21
  __int64 v51; // x9
  size_t v52; // x9
  size_t v53; // x8
  unsigned __int64 *v54; // x9
  unsigned __int64 v55; // x8
  __int64 v56; // x8
  unsigned __int64 v57; // x9
  __int64 v58; // x8
  size_t v59; // x7
  unsigned __int64 v60; // x9
  unsigned __int64 v61; // x8
  __int64 v62; // x21
  void *v63; // x26
  int v64; // w9
  const void *v65; // x25
  __int64 v66; // x26
  __int64 v67; // x19
  _QWORD *v68; // x9
  __int64 v69; // x8
  _DWORD *v70; // x10
  _DWORD *v71; // x8
  __int64 v72; // x21
  __int64 v73; // x25
  unsigned int v74; // w23
  unsigned __int64 v75; // x22
  __int64 *v76; // x8
  int v77; // w23
  void *v78; // x0
  unsigned int v79; // w19
  __int64 v80; // [xsp+18h] [xbp-A8h]
  unsigned __int64 v82; // [xsp+28h] [xbp-98h]
  unsigned __int64 v83; // [xsp+30h] [xbp-90h]
  size_t v84; // [xsp+38h] [xbp-88h]
  unsigned __int64 StatusReg; // [xsp+40h] [xbp-80h]
  _QWORD *v86; // [xsp+48h] [xbp-78h]
  __int64 v87; // [xsp+58h] [xbp-68h]
  __int64 v88; // [xsp+58h] [xbp-68h]
  _QWORD *v89; // [xsp+60h] [xbp-60h]
  __int64 v90; // [xsp+68h] [xbp-58h]
  __int64 v91; // [xsp+70h] [xbp-50h]
  __int64 v92; // [xsp+78h] [xbp-48h]
  __int64 v93; // [xsp+78h] [xbp-48h]
  __int64 v94; // [xsp+80h] [xbp-40h] BYREF
  __int64 v95; // [xsp+88h] [xbp-38h]
  __int64 v96; // [xsp+90h] [xbp-30h] BYREF
  __int64 v97; // [xsp+98h] [xbp-28h]
  __int64 v98; // [xsp+A0h] [xbp-20h] BYREF
  __int64 v99; // [xsp+A8h] [xbp-18h]
  __int64 v100; // [xsp+B0h] [xbp-10h]

  v100 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(_QWORD *)(a2 + 184);
  v4 = *(_DWORD *)(v3 + 280);
  v5 = **(_QWORD **)(v3 + 136);
  if ( v4 )
    v6 = *(_QWORD *)(a2 + 248);
  else
    v6 = 0;
  v7 = *(_DWORD *)(a2 + 16);
  v8 = *(unsigned int *)(a2 + 20);
  v82 = *(unsigned int *)(a2 + 36);
  v9 = 40 * v7;
  v10 = (int)((40 * v7 + 611) & 0xFFFFFF80);
  if ( (int)v8 >= 1 )
  {
    v11 = (_QWORD *)(*(_QWORD *)(a2 + 232) + 24LL);
    do
    {
      if ( (unsigned int)(*(_DWORD *)(*(_QWORD *)(a2 + 224) + 24LL * *((int *)v11 - 2) + 16) + 1) <= 1 )
      {
        if ( !v11[2] )
        {
          if ( v10 > 0xFFFFFFFFFFFFFF80LL )
            goto LABEL_121;
          v10 = (v10 + 127) & 0xFFFFFFFFFFFFFF80LL;
        }
        v12 = v11[1] - *v11;
        if ( __CFADD__(v12, v10) )
          goto LABEL_121;
        v10 += v12;
      }
      --v8;
      v11 += 6;
    }
    while ( v8 );
  }
  if ( !v10 )
  {
LABEL_121:
    dev_err(v5, "invalid payload size for handle 0x%x, sc 0x%x\n", *(_DWORD *)(a2 + 40), v82);
    result = 4294967282LL;
    goto LABEL_130;
  }
  v94 = 0;
  v95 = 0;
  if ( v6 )
    v13 = (_QWORD *)(v6 + 16);
  else
    v13 = nullptr;
  if ( v4 )
  {
    v14 = v5;
    if ( v13 )
    {
      ktime_get_real_ts64(&v94);
      v3 = *(_QWORD *)(a2 + 184);
      v14 = **(_QWORD **)(v3 + 136);
      v7 = *(_DWORD *)(a2 + 16);
    }
  }
  else
  {
    v14 = v5;
  }
  v87 = v6;
  v89 = v13;
  v80 = v5;
  if ( v7 >= 1 )
  {
    v15 = *(_QWORD *)(v3 + 128);
    v16 = 0;
    v17 = 0;
    v18 = 0;
    v92 = v14;
    do
    {
      v19 = *(_QWORD *)(a2 + 224);
      if ( (unsigned int)(*(_DWORD *)(v19 + v16 + 16) + 1) >= 2 )
      {
        v20 = *(int *)(a2 + 20);
        if ( v18 < v20 || !*(_DWORD *)(v15 + 52188) )
        {
          if ( *(_QWORD *)(v19 + v16 + 8) )
          {
            v21 = v18 < v20;
            v22 = (v18 >= v20) << 17;
            mutex_lock(*(_QWORD *)(a2 + 184) + 328LL);
            v23 = fastrpc_map_create(
                    *(_QWORD *)(a2 + 184),
                    *(unsigned int *)(*(_QWORD *)(a2 + 224) + v16 + 16),
                    *(_QWORD *)(*(_QWORD *)(a2 + 224) + v16),
                    0,
                    *(_QWORD *)(*(_QWORD *)(a2 + 224) + v16 + 8),
                    *(_DWORD *)(*(_QWORD *)(a2 + 224) + v16 + 20),
                    v22,
                    (__int64 *)(*(_QWORD *)(a2 + 208) + v17),
                    v21);
            mutex_unlock(*(_QWORD *)(a2 + 184) + 328LL);
            if ( v23 )
            {
              dev_err(v92, "Error Creating map %d\n", v23);
              result = 4294967274LL;
              goto LABEL_130;
            }
            v7 = *(_DWORD *)(a2 + 16);
          }
        }
      }
      ++v18;
      v17 += 8;
      v16 += 24;
    }
    while ( v18 < v7 );
    v3 = *(_QWORD *)(a2 + 184);
    v13 = v89;
  }
  v24 = v9 + 484;
  if ( *(_DWORD *)(v3 + 280) && v13 )
  {
    v96 = 0;
    v97 = 0;
    ktime_get_real_ts64(&v96);
    v98 = 0;
    v99 = 0;
    set_normalized_timespec64(&v98, v96 - v94, v97 - v95);
    if ( v98 <= 0x225C17D03LL )
    {
      if ( v98 >= (__int64)0xFFFFFFFDDA3E82FDLL )
        v25 = v99 + 1000000000 * v98;
      else
        v25 = 0x8000000000000000LL;
    }
    else
    {
      v25 = 0x7FFFFFFFFFFFFFFFLL;
    }
    *v13 += v25;
    v3 = *(_QWORD *)(a2 + 184);
  }
  *(_QWORD *)(a2 + 88) = v24;
  result = fastrpc_smmu_buf_alloc(v3, v10, 0, a2 + 216);
  if ( !(_DWORD)result )
  {
    memset(*(void **)(*(_QWORD *)(a2 + 216) + 48LL), 0, v10);
    v27 = *(_DWORD *)(a2 + 16);
    v28 = *(_DWORD *)(a2 + 20);
    v93 = *(_QWORD *)(*(_QWORD *)(a2 + 216) + 48LL);
    *(_QWORD *)(a2 + 192) = v93;
    v90 = v93 + 16LL * v27 + 8LL * v27;
    v91 = v93 + 16LL * v27;
    if ( v28 >= 1 )
    {
      v29 = 0;
      v84 = v10 - v24;
      v30 = 0;
      v31 = v93 + v24;
      if ( v87 )
        v32 = (_QWORD *)(v87 + 24);
      else
        v32 = nullptr;
      StatusReg = _ReadStatusReg(SP_EL0);
      v86 = v32;
      do
      {
        v34 = *(int *)(*(_QWORD *)(a2 + 232) + v29 + 16);
        v35 = (_QWORD *)(v93 + 16 * v34);
        v36 = *(_QWORD *)(*(_QWORD *)(a2 + 224) + 24LL * (int)v34 + 8);
        v37 = (_DWORD *)(v91 + 8 * v34);
        *v35 = 0;
        v35[1] = v36;
        *v37 = v36 != 0;
        v37[1] = v34;
        if ( v36 )
        {
          if ( *(_QWORD *)(*(_QWORD *)(a2 + 208) + 8 * v34) )
          {
            v38 = *(_QWORD *)(a2 + 224);
            v88 = v31;
            v39 = *(_DWORD *)(*(_QWORD *)(a2 + 184) + 280LL);
            v40 = *(_QWORD *)(v38 + 24LL * (int)v34);
            v94 = 0;
            v95 = 0;
            if ( v39 && v13 )
            {
              ktime_get_real_ts64(&v94);
              v38 = *(_QWORD *)(a2 + 224);
            }
            *v35 = *(_QWORD *)(v38 + 24LL * (int)v34);
            v41 = (_QWORD *)(v90 + 16 * v34);
            *v41 = *(_QWORD *)(*(_QWORD *)(*(_QWORD *)(a2 + 208) + 8 * v34) + 64LL);
            v42 = *(_QWORD *)(*(_QWORD *)(a2 + 208) + 8 * v34);
            v43 = *(_QWORD *)(v42 + 72);
            if ( v36 > v43 )
            {
              v66 = v80;
              dev_err(
                v80,
                "Invalid buffer addr 0x%llx len 0x%llx IPA 0x%llx size 0x%llx fd %d\n",
                *(_QWORD *)(*(_QWORD *)(a2 + 224) + 24LL * (int)v34),
                v36,
                *(_QWORD *)(v42 + 64),
                v43,
                *(_DWORD *)(v42 + 24));
              v79 = -14;
              goto LABEL_129;
            }
            v44 = v40 & 0xFFFFFFFFFFFFF000LL;
            if ( (*(_BYTE *)(v42 + 105) & 1) == 0 )
            {
              down_read(*(_QWORD *)(StatusReg + 1672) + 136LL);
              vma = (unsigned __int64 *)find_vma(
                                          *(_QWORD *)(StatusReg + 1672),
                                          *(_QWORD *)(*(_QWORD *)(a2 + 224) + 24LL * (int)v34));
              if ( vma )
              {
                v46 = *vma;
                v83 = vma[1];
              }
              else
              {
                v46 = 0;
                v83 = 0;
              }
              up_read(*(_QWORD *)(StatusReg + 1672) + 136LL);
              v56 = *(_QWORD *)(a2 + 208);
              v57 = v44 - v46;
              if ( v44 < v46 || v44 + v36 > v83 )
              {
                v58 = *(_QWORD *)(v56 + 8 * v34);
                v59 = *(_QWORD *)(v58 + 72);
LABEL_125:
                v66 = v80;
                dev_err(
                  v80,
                  "Invalid buffer addr 0x%llx len 0x%llx vm start 0x%llx vm end 0x%llx IPA 0x%llx size 0x%llx\n",
                  *(_QWORD *)(*(_QWORD *)(a2 + 224) + 24LL * (int)v34),
                  v36,
                  v46,
                  v83,
                  *(_QWORD *)(v58 + 64),
                  v59);
                v79 = -14;
                goto LABEL_129;
              }
              v58 = *(_QWORD *)(v56 + 8 * v34);
              v59 = *(_QWORD *)(v58 + 72);
              if ( v57 + v36 > v59 )
                goto LABEL_125;
              *v41 += v57;
            }
            v60 = ~v44;
            v31 = v88;
            v13 = v89;
            v41[1] = ((v36 + *(_QWORD *)(*(_QWORD *)(a2 + 224) + 24LL * (int)v34) + v60) & 0xFFFFFFFFFFFFF000LL) + 4096;
            if ( *(_DWORD *)(*(_QWORD *)(a2 + 184) + 280LL) && v89 )
            {
              v96 = 0;
              v97 = 0;
              ktime_get_real_ts64(&v96);
              v98 = 0;
              v99 = 0;
              set_normalized_timespec64(&v98, v96 - v94, v97 - v95);
              if ( v98 <= 0x225C17D03LL )
              {
                if ( v98 >= (__int64)0xFFFFFFFDDA3E82FDLL )
                  v61 = v99 + 1000000000 * v98;
                else
                  v61 = 0x8000000000000000LL;
              }
              else
              {
                v61 = 0x7FFFFFFFFFFFFFFFLL;
              }
              *v89 += v61;
            }
          }
          else
          {
            v47 = *(_QWORD *)(a2 + 184);
            v94 = 0;
            v95 = 0;
            if ( *(_DWORD *)(v47 + 280) && v86 )
              ktime_get_real_ts64(&v94);
            v48 = (_QWORD *)(*(_QWORD *)(a2 + 232) + v29);
            v49 = v48[5];
            v50 = v48[4] - v48[3];
            if ( v49 )
              v51 = 0;
            else
              v51 = v31 - ((v31 + 127) & 0xFFFFFFFFFFFFFF80LL);
            v52 = v51 + v84;
            v84 = v52 - v50;
            if ( v52 < v50 )
              goto LABEL_120;
            if ( !v49 )
              v31 = (v31 + 127) & 0xFFFFFFFFFFFFFF80LL;
            *v35 = v31 - v49;
            v53 = v10 + *(_QWORD *)(*(_QWORD *)(a2 + 216) + 64LL) - *(_QWORD *)(*(_QWORD *)(a2 + 232) + v29 + 40) - v52;
            v54 = (unsigned __int64 *)(v90 + 16 * v34);
            *v54 = v53 & 0xFFFFFFFFFFFFF000LL;
            v54[1] = ((*v35 + v36 + (~*v35 | 0xFFFLL)) & 0xFFFFFFFFFFFFF000LL) + 4096;
            if ( *(_DWORD *)(*(_QWORD *)(a2 + 184) + 280LL) && v86 )
            {
              v96 = 0;
              v97 = 0;
              ktime_get_real_ts64(&v96);
              v98 = 0;
              v99 = 0;
              set_normalized_timespec64(&v98, v96 - v94, v97 - v95);
              if ( v98 <= 0x225C17D03LL )
              {
                if ( v98 >= (__int64)0xFFFFFFFDDA3E82FDLL )
                  v55 = v99 + 1000000000 * v98;
                else
                  v55 = 0x8000000000000000LL;
              }
              else
              {
                v55 = 0x7FFFFFFFFFFFFFFFLL;
              }
              *v86 += v55;
            }
            v31 += v50;
          }
          if ( (int)v34 < BYTE2(v82) && !*(_QWORD *)(*(_QWORD *)(a2 + 208) + 8 * v34) )
          {
            v62 = v31;
            v63 = (void *)*v35;
            v64 = *(_DWORD *)(*(_QWORD *)(a2 + 184) + 280LL);
            v65 = *(const void **)(*(_QWORD *)(a2 + 224) + 24LL * (int)v34);
            v94 = 0;
            v95 = 0;
            if ( v64 && v86 )
              ktime_get_real_ts64(&v94);
            if ( a1 )
            {
              memcpy(v63, v65, v36);
            }
            else
            {
              if ( v36 >> 31 )
              {
                __break(0x800u);
LABEL_127:
                v66 = v80;
                dev_err(v80, "invalid buffer length 0x%llx\n", v36);
                v79 = -14;
LABEL_129:
                dev_err(v66, "Error: get invoke args failed:%d\n", v79);
                result = v79;
                goto LABEL_130;
              }
              _check_object_size(v63, v36, 0);
              if ( inline_copy_from_user((int)v63, (int)v65, v36) )
                goto LABEL_127;
            }
            v13 = v89;
            v31 = v62;
            if ( *(_DWORD *)(*(_QWORD *)(a2 + 184) + 280LL) && v86 )
            {
              v96 = 0;
              v97 = 0;
              ktime_get_real_ts64(&v96);
              v98 = 0;
              v99 = 0;
              set_normalized_timespec64(&v98, v96 - v94, v97 - v95);
              if ( v98 > 0x225C17D03LL )
              {
                v33 = 0x7FFFFFFFFFFFFFFFLL;
              }
              else if ( v98 >= (__int64)0xFFFFFFFDDA3E82FDLL )
              {
                v33 = v99 + 1000000000 * v98;
              }
              else
              {
                v33 = 0x8000000000000000LL;
              }
              *v86 += v33;
            }
          }
        }
        ++v30;
        v29 += 48;
      }
      while ( v30 < *(int *)(a2 + 20) );
    }
    v66 = v80;
    v67 = *(int *)(a2 + 20);
    if ( (int)v67 < *(_DWORD *)(a2 + 16) )
    {
      do
      {
        v71 = (_DWORD *)(v91 + 8 * v67);
        *v71 = *(_QWORD *)(*(_QWORD *)(a2 + 224) + 24 * v67 + 8) != 0;
        v71[1] = v67;
        if ( *(_QWORD *)(*(_QWORD *)(a2 + 208) + 8 * v67) )
        {
          mutex_lock(*(_QWORD *)(a2 + 184) + 328LL);
          v72 = *(_QWORD *)(a2 + 184);
          v73 = *(_QWORD *)(a2 + 208);
          v74 = *(_DWORD *)(*(_QWORD *)(a2 + 224) + 24 * v67 + 16);
          v75 = dma_buf_get(v74);
          if ( v75 < 0xFFFFFFFFFFFFF001LL )
          {
            raw_spin_lock(v72 + 320);
            v76 = *(__int64 **)(v72 + 16);
            if ( v76 == (__int64 *)(v72 + 16) )
            {
LABEL_111:
              v77 = -2;
            }
            else
            {
              while ( v76[4] != v75 || *((_DWORD *)v76 + 6) != v74 )
              {
                v76 = (__int64 *)*v76;
                if ( v76 == (__int64 *)(v72 + 16) )
                  goto LABEL_111;
              }
              v77 = 0;
              *(_QWORD *)(v73 + 8 * v67) = v76;
            }
            raw_spin_unlock(v72 + 320);
            dma_buf_put(v75);
            if ( !v77 )
            {
              v68 = (_QWORD *)(v90 + 16 * v67);
              *v68 = *(_QWORD *)(*(_QWORD *)(*(_QWORD *)(a2 + 208) + 8 * v67) + 64LL);
              v68[1] = *(_QWORD *)(*(_QWORD *)(*(_QWORD *)(a2 + 208) + 8 * v67) + 72LL);
            }
          }
          mutex_unlock(*(_QWORD *)(a2 + 184) + 328LL);
        }
        v69 = 24 * v67;
        v70 = (_DWORD *)(v93 + 16 * v67++);
        *v70 = *(_DWORD *)(*(_QWORD *)(a2 + 224) + v69 + 16);
        v70[2] = *(_QWORD *)(*(_QWORD *)(a2 + 224) + v69 + 8);
        v70[1] = *(_QWORD *)(*(_QWORD *)(a2 + 224) + v69);
      }
      while ( v67 < *(int *)(a2 + 16) );
    }
    v78 = (void *)_kmalloc_noprof((v82 >> 4) & 0xFF0, 3520);
    *(_QWORD *)(a2 + 200) = v78;
    if ( !v78 )
    {
      v79 = -12;
      goto LABEL_129;
    }
    memcpy(v78, (const void *)(v93 + 16LL * BYTE2(v82)), (v82 >> 4) & 0xFF0);
LABEL_120:
    result = 0;
  }
LABEL_130:
  _ReadStatusReg(SP_EL0);
  return result;
}
