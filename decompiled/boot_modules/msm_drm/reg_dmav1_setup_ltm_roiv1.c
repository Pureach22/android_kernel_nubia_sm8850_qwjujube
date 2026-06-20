__int64 __fastcall reg_dmav1_setup_ltm_roiv1(int *a1, _QWORD *a2, __int64 a3, __int64 a4)
{
  const void *v6; // x1
  __int64 v7; // x8
  __int64 v8; // x4
  __int64 v9; // x9
  __int64 result; // x0
  long double v11; // q0
  _DWORD *v12; // x21
  int v13; // w1
  int v14; // w5
  unsigned int v15; // w6
  int v16; // w4
  int v17; // w8
  unsigned int v18; // w6
  int v19; // w10
  int v20; // w11
  int v21; // [xsp+Ch] [xbp-34h] BYREF
  __int64 v22; // [xsp+10h] [xbp-30h] BYREF
  int v23; // [xsp+18h] [xbp-28h]
  _QWORD v24[2]; // [xsp+20h] [xbp-20h] BYREF
  int v25; // [xsp+30h] [xbp-10h]
  __int64 v26; // [xsp+38h] [xbp-8h]

  v26 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v25 = 0;
  v24[0] = 0;
  v24[1] = 0;
  v21 = 0;
  v23 = 0;
  v22 = 0;
  if ( !a1 || !a2 )
  {
    result = _drm_err("invalid ctx %pK cfg %pK\n", a1, a2);
LABEL_24:
    _ReadStatusReg(SP_EL0);
    return result;
  }
  v6 = (const void *)a2[2];
  v7 = (unsigned int)a1[16];
  v8 = (unsigned int)a1[374];
  if ( !v6 || (unsigned int)v7 > 4 || (unsigned int)v8 >= 2 )
  {
    result = _drm_err("invalid ctl %pK dspp idx %d feature %d dpu idx %d\n", v6, v7, 16, v8);
    goto LABEL_24;
  }
  v9 = (16 * v7) | (8 * v8);
  if ( (v9 | 0x500uLL) <= 0x7D0 && v9 != 720 )
  {
    if ( ltm_buf[2 * v7 + 160 + v8] )
    {
      result = reg_dmav1_get_ltm_blk(a2, (unsigned int)v7, v24, &v21);
      if ( (_DWORD)result != -114 )
      {
        if ( (_DWORD)result )
        {
          result = _drm_err("failed to get the blk info\n");
        }
        else
        {
          v12 = (_DWORD *)*a2;
          if ( *a2 )
          {
            v13 = *((_DWORD *)a2 + 2);
            if ( v13 == 24 )
            {
              v14 = v12[2];
              v15 = *((_DWORD *)a2 + 11);
              if ( v14 + *v12 > v15 )
              {
                *(double *)&v11 = _drm_dev_dbg(0, 0, 1, "invalid input = [%u,%u], displayh = %u\n", *v12, v14, v15);
                LOWORD(v14) = -1;
                v12[2] = 0xFFFF;
              }
              v16 = v12[1];
              v17 = v12[3];
              v18 = *((_DWORD *)a2 + 10);
              if ( v17 + v16 > v18 )
              {
                *(double *)&v11 = _drm_dev_dbg(0, 0, 1, "invalid input = [%u,%u], displayv = %u\n", v16, v17, v18);
                v16 = v12[1];
                LOWORD(v14) = *((_WORD *)v12 + 4);
                LOWORD(v17) = -1;
                v12[3] = 0xFFFF;
              }
              v20 = v12[4];
              v19 = v12[5];
              LODWORD(v22) = *(unsigned __int16 *)v12 | (v16 << 16);
              HIDWORD(v22) = (unsigned __int16)v14 | ((unsigned __int16)v17 << 16);
              v23 = v19 & 0x1FF | ((v20 & 0x1FF) << 16);
              result = reg_dmav1_setup_ltm_roi_v1_common(a1, a2, &v22, 3, v11);
            }
            else
            {
              result = _drm_err("invalid size of payload len %d exp %zd\n", v13, 0x18u);
            }
          }
          else
          {
            _drm_dev_dbg(0, 0, 1, "Disable LTM roi feature\n");
            sde_evtlog_log(sde_dbg_base_evtlog, "reg_dmav1_setup_ltm_roiv1", 5409, -1, a1[16], a1[374], a1[7], 0, 239);
            result = ltm_roiv1_disable(a1, a2, *((unsigned int *)a2 + 7), v24);
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
  return reg_dmav1_get_ltm_blk(a1, v6, a3, a4);
}
