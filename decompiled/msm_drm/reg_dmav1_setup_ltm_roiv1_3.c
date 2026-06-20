__int64 __fastcall reg_dmav1_setup_ltm_roiv1_3(int *a1, _QWORD *a2, double a3, double a4, double a5, double a6)
{
  __int64 v6; // x15
  __int64 v7; // d14
  const void *v10; // x1
  __int64 v11; // x8
  __int64 v12; // x4
  __int64 v13; // x9
  __int64 result; // x0
  _DWORD *v15; // x21
  int v16; // w1
  int v17; // w5
  unsigned int v18; // w6
  int v19; // w4
  int v20; // w8
  unsigned int v21; // w6
  unsigned int v22; // w10
  int v23; // w11
  int v24; // [xsp+Ch] [xbp-34h] BYREF
  __int64 v25; // [xsp+10h] [xbp-30h] BYREF
  __int64 v26; // [xsp+18h] [xbp-28h]
  _QWORD v27[2]; // [xsp+20h] [xbp-20h] BYREF
  int v28; // [xsp+30h] [xbp-10h]
  __int64 v29; // [xsp+38h] [xbp-8h]

  v29 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v28 = 0;
  v27[0] = 0;
  v27[1] = 0;
  v24 = 0;
  v25 = 0;
  v26 = 0;
  if ( !a1 || !a2 )
  {
    result = _drm_err("invalid ctx %pK cfg %pK\n", a1, a2);
LABEL_24:
    _ReadStatusReg(SP_EL0);
    return result;
  }
  v10 = (const void *)a2[2];
  v11 = (unsigned int)a1[16];
  v12 = (unsigned int)a1[374];
  if ( !v10 || (unsigned int)v11 > 4 || (unsigned int)v12 >= 2 )
  {
    result = _drm_err("invalid ctl %pK dspp idx %d feature %d dpu idx %d\n", v10, v11, 16, v12);
    goto LABEL_24;
  }
  v13 = (16 * v11) | (8 * v12);
  if ( (v13 | 0x500uLL) <= 0x7D0 && v13 != 720 )
  {
    if ( ltm_buf[2 * v11 + 160 + v12] )
    {
      result = reg_dmav1_get_ltm_blk((__int64)a2, (unsigned int)v11, v27, &v24);
      if ( (_DWORD)result != -114 )
      {
        if ( (_DWORD)result )
        {
          result = _drm_err("failed to get the blk info\n");
        }
        else
        {
          v15 = (_DWORD *)*a2;
          if ( *a2 )
          {
            v16 = *((_DWORD *)a2 + 2);
            if ( v16 == 24 )
            {
              v17 = v15[2];
              v18 = *((_DWORD *)a2 + 11);
              if ( v17 + *v15 > v18 )
              {
                _drm_dev_dbg(0, 0, 1, "invalid input = [%u,%u], displayh = %u\n", *v15, v17, v18);
                LOWORD(v17) = -1;
                v15[2] = 0xFFFF;
              }
              v19 = v15[1];
              v20 = v15[3];
              v21 = *((_DWORD *)a2 + 10);
              if ( v20 + v19 > v21 )
              {
                _drm_dev_dbg(0, 0, 1, "invalid input = [%u,%u], displayv = %u\n", v19, v20, v21);
                v19 = v15[1];
                LOWORD(v17) = *((_WORD *)v15 + 4);
                LOWORD(v20) = -1;
                v15[3] = 0xFFFF;
              }
              v23 = v15[4];
              v22 = v15[5];
              LODWORD(v25) = *(unsigned __int16 *)v15 | (v19 << 16);
              HIDWORD(v25) = (unsigned __int16)v17 | ((unsigned __int16)v20 << 16);
              LODWORD(v26) = v22 & 0x1FF | ((v23 & 0x1FF) << 16);
              HIDWORD(v26) = v23 & 0x1FF0000 | HIWORD(v22) & 0x1FF;
              result = reg_dmav1_setup_ltm_roi_v1_common(a1, (__int64)a2, (__int64)&v25, 4);
            }
            else
            {
              result = _drm_err("invalid size of payload len %d exp %zd\n", v16, 0x18u);
            }
          }
          else
          {
            _drm_dev_dbg(0, 0, 1, "Disable LTM roi feature\n");
            sde_evtlog_log(sde_dbg_base_evtlog, "reg_dmav1_setup_ltm_roiv1_3", 5477, -1, a1[16], a1[374], a1[7], 0, 239);
            result = ltm_roiv1_disable((unsigned int *)a1, (__int64)a2, *((_DWORD *)a2 + 7), (__int64)v27);
          }
        }
      }
    }
    else
    {
      result = _drm_err("invalid dma_buf\n");
    }
    goto LABEL_24;
  }
  __break(1u);
  *(_QWORD *)(v6 - 24) = v7;
  *(double *)(v6 - 16) = a6;
  return reg_dmav1_setup_ltm_vlutv1();
}
