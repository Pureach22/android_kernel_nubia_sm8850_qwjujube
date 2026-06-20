__int64 __fastcall sde_hw_ctl_update_intf_cfg(__int64 a1, _DWORD *a2, int a3)
{
  __int64 result; // x0
  __int64 v7; // x0
  int v8; // w8
  __int64 v9; // x2
  int v10; // w9
  __int64 v11; // x9
  unsigned int v12; // w10
  unsigned int v13; // w9
  int v14; // w9
  __int64 v15; // x9
  unsigned int v16; // w10
  unsigned int v17; // w9
  int v18; // w9
  __int64 v19; // x9
  unsigned int v20; // w10
  unsigned int v21; // w9
  int v22; // w8
  __int64 v23; // x8
  unsigned int v24; // w9
  unsigned int v25; // w8
  unsigned int v26; // w22
  int v27; // w8
  bool v28; // cf
  char v29; // w8
  int v30; // w10
  __int64 v31; // x8
  int v32; // w8
  __int64 v33; // x2
  int v34; // w9
  __int64 v35; // x9
  unsigned int v36; // w10
  unsigned int v37; // w9
  int v38; // w8
  __int64 v39; // x2
  int v40; // w9
  __int64 v41; // x9
  unsigned int v42; // w10
  unsigned int v43; // w9
  int v44; // w8
  __int64 v45; // x8
  unsigned int v46; // w9
  unsigned int v47; // w8
  int v48; // w8
  __int64 v49; // x2
  int v50; // w9
  __int64 v51; // x9
  unsigned int v52; // w10
  unsigned int v53; // w9
  int v54; // w9
  __int64 v55; // x9
  unsigned int v56; // w10
  unsigned int v57; // w9
  int v58; // w9
  __int64 v59; // x9
  unsigned int v60; // w10
  unsigned int v61; // w9
  int v62; // w8
  __int64 v63; // x8
  unsigned int v64; // w9
  unsigned int v65; // w8
  int v66; // w8
  __int64 v67; // x2
  int v68; // w9
  __int64 v69; // x9
  unsigned int v70; // w10
  unsigned int v71; // w9

  result = 4294967274LL;
  if ( a1 && a2 )
  {
    if ( a2[10] )
    {
      v7 = sde_reg_read(a1, 240);
      v8 = a2[10];
      v9 = (unsigned int)v7;
      if ( v8 )
      {
        if ( (unsigned int)(v8 - 5) < 0xFFFFFFFC )
          goto LABEL_88;
        v10 = a2[11];
        if ( v10 )
        {
          v11 = 1LL << ((unsigned __int8)v10 - 1);
          v12 = v11 | v7;
          v13 = v7 & ~(_DWORD)v11;
          if ( (a3 & 1) != 0 )
            v9 = v12;
          else
            v9 = v13;
        }
        if ( v8 != 1 )
        {
          v14 = a2[12];
          if ( v14 )
          {
            v15 = 1LL << ((unsigned __int8)v14 - 1);
            v16 = v15 | v9;
            v17 = v9 & ~(_DWORD)v15;
            if ( (a3 & 1) != 0 )
              v9 = v16;
            else
              v9 = v17;
          }
          if ( v8 != 2 )
          {
            v18 = a2[13];
            if ( v18 )
            {
              v19 = 1LL << ((unsigned __int8)v18 - 1);
              v20 = v19 | v9;
              v21 = v9 & ~(_DWORD)v19;
              if ( (a3 & 1) != 0 )
                v9 = v20;
              else
                v9 = v21;
            }
            if ( v8 != 3 )
            {
              v22 = a2[14];
              if ( v22 )
              {
                v23 = 1LL << ((unsigned __int8)v22 - 1);
                v24 = v23 | v9;
                v25 = v9 & ~(_DWORD)v23;
                if ( (a3 & 1) != 0 )
                  v9 = v24;
                else
                  v9 = v25;
              }
            }
          }
        }
      }
      v26 = a2[5];
      if ( v26 )
      {
        if ( v26 != 1 )
          goto LABEL_88;
        v27 = a2[6];
        v28 = v27 != 0;
        v29 = v27 - 1;
        v30 = v28;
        v31 = 1LL << v29;
        if ( (v30 & a3) != 0 )
          v26 = v31;
        else
          v26 = 0;
      }
      sde_reg_write(a1, 240, v9, "CTL_CWB_ACTIVE");
      sde_reg_write(a1, 236, v26, "CTL_WB_ACTIVE");
    }
    if ( a2[24] )
    {
      v7 = sde_reg_read(a1, 236);
      v32 = a2[24];
      v33 = (unsigned int)v7;
      if ( v32 )
      {
        v34 = a2[25];
        if ( v34 )
        {
          v35 = 1LL << ((unsigned __int8)v34 + 15);
          v36 = v35 | v7;
          v37 = v7 & ~(_DWORD)v35;
          if ( (a3 & 1) != 0 )
            v33 = v36;
          else
            v33 = v37;
        }
        if ( v32 != 1 )
          goto LABEL_88;
      }
      sde_reg_write(a1, 236, v33, "CTL_WB_ACTIVE");
    }
    if ( a2[7] )
    {
      v7 = sde_reg_read(a1, 228);
      v38 = a2[7];
      v39 = (unsigned int)v7;
      if ( v38 )
      {
        if ( (unsigned int)(v38 - 3) < 0xFFFFFFFE )
          goto LABEL_88;
        v40 = a2[8];
        if ( v40 )
        {
          v41 = 1LL << ((unsigned __int8)v40 - 1);
          v42 = v41 | v7;
          v43 = v7 & ~(_DWORD)v41;
          if ( (a3 & 1) != 0 )
            v39 = v42;
          else
            v39 = v43;
        }
        if ( v38 != 1 )
        {
          v44 = a2[9];
          if ( v44 )
          {
            v45 = 1LL << ((unsigned __int8)v44 - 1);
            v46 = v45 | v39;
            v47 = v39 & ~(_DWORD)v45;
            if ( (a3 & 1) != 0 )
              v39 = v46;
            else
              v39 = v47;
          }
        }
      }
      sde_reg_write(a1, 228, v39, "CTL_MERGE_3D_ACTIVE");
    }
    if ( a2[17] )
    {
      v7 = sde_reg_read(a1, 232);
      v48 = a2[17];
      v49 = (unsigned int)v7;
      if ( v48 )
      {
        if ( (unsigned int)(v48 - 5) < 0xFFFFFFFC )
          goto LABEL_88;
        v50 = a2[18];
        if ( v50 )
        {
          v51 = 1LL << ((unsigned __int8)v50 - 1);
          v52 = v51 | v7;
          v53 = v7 & ~(_DWORD)v51;
          if ( (a3 & 1) != 0 )
            v49 = v52;
          else
            v49 = v53;
        }
        if ( v48 != 1 )
        {
          v54 = a2[19];
          if ( v54 )
          {
            v55 = 1LL << ((unsigned __int8)v54 - 1);
            v56 = v55 | v49;
            v57 = v49 & ~(_DWORD)v55;
            if ( (a3 & 1) != 0 )
              v49 = v56;
            else
              v49 = v57;
          }
          if ( v48 != 2 )
          {
            v58 = a2[20];
            if ( v58 )
            {
              v59 = 1LL << ((unsigned __int8)v58 - 1);
              v60 = v59 | v49;
              v61 = v49 & ~(_DWORD)v59;
              if ( (a3 & 1) != 0 )
                v49 = v60;
              else
                v49 = v61;
            }
            if ( v48 != 3 )
            {
              v62 = a2[21];
              if ( v62 )
              {
                v63 = 1LL << ((unsigned __int8)v62 - 1);
                v64 = v63 | v49;
                v65 = v49 & ~(_DWORD)v63;
                if ( (a3 & 1) != 0 )
                  v49 = v64;
                else
                  v49 = v65;
              }
            }
          }
        }
      }
      sde_reg_write(a1, 232, v49, "CTL_DSC_ACTIVE");
    }
    if ( !a2[22] )
      return 0;
    v7 = sde_reg_read(a1, 232);
    v66 = a2[22];
    v67 = (unsigned int)v7;
    if ( !v66 )
      goto LABEL_85;
    v68 = a2[23];
    if ( v68 )
    {
      v69 = 1LL << ((unsigned __int8)v68 + 15);
      v70 = v69 | v7;
      v71 = v7 & ~(_DWORD)v69;
      if ( (a3 & 1) != 0 )
        v67 = v70;
      else
        v67 = v71;
    }
    if ( v66 == 1 )
    {
LABEL_85:
      sde_reg_write(a1, 232, v67, "CTL_DSC_ACTIVE");
      return 0;
    }
LABEL_88:
    __break(0x5512u);
    return sde_hw_ctl_update_bitmask_v1(v7);
  }
  return result;
}
