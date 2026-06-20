__int64 __fastcall cam_vfe_bus_handle_vfe_out_done_bottom_half(int *a1, _DWORD *a2)
{
  __int64 v4; // x22
  __int64 v5; // x9
  unsigned int *v6; // x25
  unsigned int v7; // w6
  unsigned __int64 v8; // x8
  unsigned int v9; // w21
  char v10; // w9
  __int64 (*v11)(void); // x8
  unsigned int v12; // w25
  unsigned __int64 v13; // x8
  __int64 v14; // x0
  __int64 v15; // x9
  __int64 v16; // x11
  __int64 v17; // x1
  int v18; // w10
  int v19; // w8
  int v20; // w9
  void (__fastcall *v21)(__int64, __int64, __int64 *); // x8
  __int64 v23; // x23
  _DWORD *v24; // [xsp+8h] [xbp-48h] BYREF
  _QWORD v25[2]; // [xsp+10h] [xbp-40h] BYREF
  __int64 v26; // [xsp+20h] [xbp-30h] BYREF
  __int64 v27; // [xsp+28h] [xbp-28h]
  __int64 v28; // [xsp+30h] [xbp-20h]
  __int64 v29; // [xsp+38h] [xbp-18h]
  _QWORD *v30; // [xsp+40h] [xbp-10h]
  __int64 v31; // [xsp+48h] [xbp-8h]

  v31 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *((_QWORD *)a1 + 3);
  v29 = 0;
  v30 = nullptr;
  v27 = 0;
  v28 = 0;
  v5 = *(_QWORD *)(v4 + 40);
  v25[1] = 0;
  v26 = 0;
  v24 = a2;
  v25[0] = 0;
  if ( v5 )
  {
    v6 = *(unsigned int **)(v5 + 24);
    if ( (debug_mdl & 8) != 0 && !debug_priority )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 8,
        4,
        "cam_vfe_bus_handle_comp_done_bottom_half",
        1883,
        "comp grp type %d",
        *v6);
      if ( a2 )
      {
LABEL_5:
        v7 = *v6;
        if ( *v6 - 6 < 6 )
        {
          v13 = (unsigned int)a2[12];
          if ( (v13 & 0x40) != 0 && (v6[11] & a2[15]) != 0 )
          {
LABEL_19:
            a2[9] = 0;
            v9 = -3;
            v12 = *v6;
            goto LABEL_33;
          }
          if ( (v13 & 0x80) != 0 && (v6[11] & a2[16]) != 0 )
          {
LABEL_22:
            a2[9] = 0;
            v9 = -2;
            v12 = *v6;
            goto LABEL_33;
          }
          if ( ((v13 >> ((unsigned __int8)v7 - 6)) & 1) != 0 )
          {
            v9 = 0;
            a2[9] = 5;
            v12 = *v6;
            goto LABEL_33;
          }
        }
        else
        {
          if ( v7 <= 5 )
          {
            v8 = (unsigned int)a2[10];
            if ( (v8 & 0x800) == 0 || (v6[11] & a2[13]) == 0 )
            {
              if ( (v8 & 0x1000) == 0 || (v6[11] & a2[14]) == 0 )
              {
                if ( ((v8 >> ((unsigned __int8)v7 + 5)) & 1) != 0 )
                {
                  v9 = 0;
                  a2[9] = 5;
                  v10 = debug_mdl;
                  if ( (debug_mdl & 8) == 0 )
                    goto LABEL_30;
                }
                else
                {
                  v9 = -1;
                  v10 = debug_mdl;
                  if ( (debug_mdl & 8) == 0 )
                    goto LABEL_30;
                }
                if ( !debug_priority )
                {
                  ((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                    3,
                    v10 & 8,
                    4,
                    "cam_vfe_bus_handle_comp_done_bottom_half",
                    1928,
                    "status reg = 0x%x, bit index = %d rc %d",
                    v8,
                    v7 + 5,
                    v9);
                  v12 = *v6;
                  goto LABEL_33;
                }
LABEL_30:
                v12 = *v6;
                goto LABEL_33;
              }
              goto LABEL_22;
            }
            goto LABEL_19;
          }
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            8,
            1,
            "cam_vfe_bus_handle_comp_done_bottom_half",
            1971,
            "Invalid comp_grp_type %u",
            v7);
        }
        v9 = -1;
        goto LABEL_30;
      }
    }
    else if ( a2 )
    {
      goto LABEL_5;
    }
    v12 = 0;
    v9 = -1;
    goto LABEL_33;
  }
  v11 = *(__int64 (**)(void))(*(_QWORD *)(v4 + 24) + 120LL);
  if ( *((_DWORD *)v11 - 1) != 1863972096 )
    __break(0x8228u);
  v9 = v11();
  v12 = 0;
LABEL_33:
  v14 = *(_QWORD *)(v4 + 104);
  if ( (debug_mdl & 8) != 0 && !debug_priority )
  {
    v23 = *(_QWORD *)(v4 + 104);
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 8,
      4,
      "cam_vfe_bus_handle_vfe_out_done_bottom_half",
      2442,
      "vfe_out %d rc %d",
      *(_DWORD *)v4,
      v9);
    v14 = v23;
    if ( v9 )
      goto LABEL_42;
  }
  else if ( v9 )
  {
    goto LABEL_42;
  }
  v15 = *((_QWORD *)a1 + 2);
  v16 = *(_QWORD *)(v4 + 40);
  HIDWORD(v28) = 2;
  v17 = (unsigned int)a2[9];
  v18 = *(_DWORD *)(v15 + 4);
  v19 = *a1;
  v20 = a1[1];
  HIDWORD(v27) = v18;
  LODWORD(v26) = v19;
  if ( v16 )
    HIDWORD(v25[0]) = v12;
  LODWORD(v25[0]) = v20;
  v30 = v25;
  v21 = *(void (__fastcall **)(__int64, __int64, __int64 *))(*(_QWORD *)(v4 + 8) + 33600LL);
  if ( v21 )
  {
    if ( *((_DWORD *)v21 - 1) != 414296116 )
      __break(0x8228u);
    v21(v14, v17, &v26);
  }
LABEL_42:
  cam_vfe_bus_put_evt_payload(*(_QWORD *)(v4 + 8), &v24);
  _ReadStatusReg(SP_EL0);
  return v9;
}
