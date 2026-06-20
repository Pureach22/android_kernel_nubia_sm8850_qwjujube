__int64 __fastcall sde_cp_ad_validate_prop(__int64 a1, __int64 a2)
{
  unsigned int disp_op; // w0
  unsigned __int64 v5; // x9
  unsigned int v6; // w21
  __int64 v7; // x22
  _QWORD *v8; // x23
  int v9; // w25
  unsigned __int64 v10; // x28
  int v11; // w10
  unsigned int v12; // w8
  __int64 (*v13)(void); // x10
  unsigned int v14; // w0

  _ReadStatusReg(SP_EL0);
  disp_op = sde_crtc_get_disp_op(a2);
  v5 = *(unsigned int *)(a2 + 2192);
  if ( (_DWORD)v5 )
  {
    v6 = disp_op;
    v7 = disp_op;
    v8 = (_QWORD *)(a2 + 2216);
    if ( disp_op == 1 )
      v9 = 0;
    else
      v9 = -22;
    v10 = 1;
    while ( 1 )
    {
      if ( v10 == 9 )
LABEL_28:
        __break(0x5512u);
      if ( !*v8 )
        break;
      v11 = *(_DWORD *)(a1 + 8);
      v12 = 0;
      if ( v11 > 18 )
      {
        if ( v11 > 21 && v11 != 22 )
          goto LABEL_27;
      }
      else if ( v11 <= 16 && v11 != 15 && v11 != 16 )
      {
        goto LABEL_27;
      }
      if ( v6 > 2 )
        goto LABEL_28;
      v13 = *(__int64 (**)(void))(*v8 + 8 * v7 + 496);
      v12 = v9;
      if ( v13 )
      {
        if ( *((_DWORD *)v13 - 1) != -1077458825 )
          __break(0x822Au);
        v14 = v13();
        v5 = *(unsigned int *)(a2 + 2192);
        v12 = v14;
      }
      if ( v10 < v5 )
      {
        ++v10;
        v8 += 6;
        if ( !v12 )
          continue;
      }
      goto LABEL_27;
    }
    v12 = -22;
  }
  else
  {
    v12 = 0;
  }
LABEL_27:
  _ReadStatusReg(SP_EL0);
  return v12;
}
