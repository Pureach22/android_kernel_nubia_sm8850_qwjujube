unsigned __int64 __fastcall ltm_roiv1_disable(unsigned int *a1, __int64 a2, int a3, __int64 a4)
{
  __int64 v4; // x24
  unsigned __int64 result; // x0
  unsigned __int64 v10; // x21
  __int64 v11; // x8
  __int64 (__fastcall *v12)(_QWORD); // x9
  __int64 v13; // x0
  int v14; // w8
  __int64 v15; // x8
  int v16; // w28
  __int64 v17; // x8
  int v18; // w8
  __int64 (__fastcall *v19)(_QWORD); // x9
  unsigned int v20; // w0
  __int64 v21; // x9
  __int64 v22; // x8
  char *v23; // x9
  int v24; // w10
  __int64 (__fastcall *v25)(_QWORD); // x8
  __int64 v26; // x1
  __int64 v27; // x8
  __int64 v28; // x9
  __int64 v29; // x10
  __int64 v30; // x8
  __int64 v31; // x8
  __int64 (__fastcall *v32)(_QWORD); // x8
  _QWORD *v33; // [xsp+8h] [xbp-B8h]
  __int64 v34; // [xsp+10h] [xbp-B0h]
  int v35; // [xsp+1Ch] [xbp-A4h] BYREF
  __int64 v36; // [xsp+20h] [xbp-A0h] BYREF
  __int64 v37; // [xsp+28h] [xbp-98h]
  __int64 v38; // [xsp+30h] [xbp-90h]
  _QWORD v39[5]; // [xsp+38h] [xbp-88h] BYREF
  int v40; // [xsp+60h] [xbp-60h]
  int v41; // [xsp+64h] [xbp-5Ch]
  int v42; // [xsp+68h] [xbp-58h]
  int v43; // [xsp+6Ch] [xbp-54h]
  __int64 v44; // [xsp+70h] [xbp-50h] BYREF
  __int128 v45; // [xsp+78h] [xbp-48h]
  __int64 v46; // [xsp+88h] [xbp-38h]
  int *v47; // [xsp+90h] [xbp-30h]
  __int64 v48; // [xsp+98h] [xbp-28h]
  __int64 v49; // [xsp+A0h] [xbp-20h]
  __int64 v50; // [xsp+A8h] [xbp-18h]
  __int64 v51; // [xsp+B0h] [xbp-10h]

  v51 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = a1[16];
  v49 = 0;
  v50 = 0;
  v47 = nullptr;
  v48 = 0;
  v46 = 0;
  v44 = 0;
  v45 = 0u;
  v35 = 0;
  if ( (unsigned int)v4 >= 5 )
  {
    result = _drm_err("invalid ltm idx %d\n", (unsigned int)v4);
    goto LABEL_3;
  }
  result = sde_reg_dma_get_ops(a1[374]);
  if ( result )
  {
    v10 = result;
    if ( result <= 0xFFFFFFFFFFFFF000LL )
    {
      v11 = a1[374];
      if ( (unsigned int)v11 >= 2 )
        goto LABEL_38;
      v34 = 16 * v4;
      if ( ((16 * v4) | (8 * v11) | 0x500uLL) <= 0x7D0 )
      {
        v33 = &ltm_buf[2 * v4];
        v12 = *(__int64 (__fastcall **)(_QWORD))(result + 64);
        v13 = v33[v11 + 160];
        if ( *((_DWORD *)v12 - 1) != -870478129 )
          __break(0x8229u);
        result = v12(v13);
        v14 = ltm_mapping[v4];
        LODWORD(v44) = 0;
        v45 = 0x10u;
        v49 = 0;
        v50 = 0;
        HIDWORD(v44) = v14;
        v15 = a1[374];
        v46 = 0;
        v47 = nullptr;
        v48 = 0;
        if ( (unsigned int)v15 > 1 )
        {
LABEL_38:
          __break(0x5512u);
        }
        else if ( (v34 | (8 * v15) | 0x500uLL) <= 0x7D0 )
        {
          v46 = v33[v15 + 160];
          if ( !a3 )
          {
            v38 = 0;
            memset(v39, 0, 24);
            v36 = *(_QWORD *)(a2 + 16);
            v37 = 0;
            goto LABEL_28;
          }
          v16 = 0;
          do
          {
            v17 = *(unsigned int *)(a4 + 4LL * v16);
            if ( (unsigned int)v17 > 4 )
              goto LABEL_38;
            HIDWORD(v45) = 0;
            *(_QWORD *)((char *)&v45 + 4) = 0;
            v18 = ltm_mapping[v17];
            v47 = nullptr;
            v48 = 0;
            v19 = *(__int64 (__fastcall **)(_QWORD))(v10 + 8);
            LODWORD(v44) = 0;
            HIDWORD(v44) = v18;
            if ( *((_DWORD *)v19 - 1) != -1839634494 )
              __break(0x8229u);
            v20 = v19(&v44);
            if ( v20 )
            {
              result = _drm_err("write decode select failed ret %d\n", v20);
              goto LABEL_3;
            }
            v21 = *(unsigned int *)(a4 + 4LL * v16);
            if ( (unsigned int)v21 > 4 )
              goto LABEL_38;
            v22 = a1[374];
            if ( (unsigned int)v22 > 1 )
              goto LABEL_38;
            if ( ((8 * v21) | (unsigned __int64)(4 * v22)) > 0x27 )
              goto LABEL_39;
            HIDWORD(v45) = 4;
            v23 = (char *)&ltm_vlut_ops_mask + 8 * v21;
            *(_QWORD *)((char *)&v45 + 4) = 0;
            v47 = &v35;
            v48 = 0x4FEFFFFFFLL;
            v24 = *(_DWORD *)&v23[4 * v22];
            LODWORD(v44) = 5;
            *(_DWORD *)&v23[4 * v22] = v24 & 0xFFFFFFFB;
            v25 = *(__int64 (__fastcall **)(_QWORD))(v10 + 8);
            if ( *((_DWORD *)v25 - 1) != -1839634494 )
              __break(0x8228u);
            result = v25(&v44);
            if ( (_DWORD)result )
            {
              result = _drm_err("opmode write failed ret %d\n", (unsigned int)result);
              goto LABEL_3;
            }
            ++v16;
          }
          while ( a3 != v16 );
          LODWORD(v15) = a1[374];
          v38 = 0;
          memset(v39, 0, 24);
          v36 = *(_QWORD *)(a2 + 16);
          v37 = 0;
          if ( (unsigned int)v15 > 1 )
            goto LABEL_38;
LABEL_28:
          v26 = (unsigned int)v15;
          v27 = v34 | (8LL * (unsigned int)v15);
          if ( (v27 | 0x500uLL) <= 0x7D0 && v27 != 720 )
          {
            LODWORD(v37) = 1;
            *(_QWORD *)((char *)&v39[1] + 4) = 0x1000000000LL;
            v28 = *(_QWORD *)(a2 + 152);
            v29 = *(_QWORD *)(a2 + 160);
            *(_QWORD *)((char *)v39 + 4) = 0;
            v30 = v33[v26 + 160];
            v39[3] = v28;
            v39[4] = v29;
            LODWORD(v29) = *(_DWORD *)(a2 + 28);
            v38 = v30;
            LODWORD(v30) = *(_DWORD *)(a2 + 176);
            v42 = *(_DWORD *)(a2 + 172);
            v43 = v30;
            v31 = a1[7];
            v40 = *(_DWORD *)(a2 + 168);
            v41 = v29;
            if ( (unsigned int)v31 > 2 )
              goto LABEL_38;
            v32 = *(__int64 (__fastcall **)(_QWORD))(v10 + 8 * v31 + 16);
            if ( v32 )
            {
              if ( *((_DWORD *)v32 - 1) != 1772228465 )
                __break(0x8228u);
              result = v32(&v36);
              if ( (_DWORD)result )
                result = _drm_err("failed to kick off ret %d\n", (unsigned int)result);
            }
            goto LABEL_3;
          }
        }
      }
LABEL_39:
      __break(1u);
    }
  }
LABEL_3:
  _ReadStatusReg(SP_EL0);
  return result;
}
