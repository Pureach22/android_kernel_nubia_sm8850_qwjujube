__int64 __fastcall sde_encoder_trigger_kickoff_pending(__int64 a1)
{
  __int64 v2; // x8
  __int64 result; // x0
  unsigned int v4; // w9
  __int64 v5; // x10
  __int64 v6; // x20
  __int64 v7; // x8
  void (__fastcall *v8)(_QWORD); // x10
  unsigned int v9; // w21
  __int64 v10; // x10
  __int64 v11; // x8
  void (__fastcall *v12)(_QWORD); // x10
  unsigned int v13; // w21
  __int64 v14; // x10
  __int64 v15; // x8
  void (__fastcall *v16)(_QWORD); // x10
  unsigned int v17; // w21
  __int64 v18; // x10
  __int64 v19; // x8
  __int64 (__fastcall *v20)(_QWORD); // x10
  void *v21; // x0

  if ( !a1 )
    return printk(&unk_26FCAB, "sde_encoder_trigger_kickoff_pending");
  if ( !*(_QWORD *)a1 )
  {
    v21 = &unk_26FCAB;
    goto LABEL_51;
  }
  v2 = *(_QWORD *)(*(_QWORD *)a1 + 56LL);
  if ( !v2 || !*(_QWORD *)(v2 + 8) )
    goto LABEL_48;
  result = sde_kms_get_disp_op();
  while ( !*(_QWORD *)(a1 + 4960) )
  {
    v4 = *(_DWORD *)(a1 + 196);
    if ( !v4 )
      break;
    v5 = *(_QWORD *)(a1 + 200);
    v6 = (unsigned int)result;
    if ( v5 )
    {
      v7 = *(_QWORD *)(v5 + 416);
      if ( v7 )
      {
        if ( v5 == *(_QWORD *)(a1 + 328) && *(_DWORD *)(a1 + 648) == 2 )
        {
          if ( (unsigned int)result > 2 )
            goto LABEL_47;
          v8 = *(void (__fastcall **)(_QWORD))(v7 + 8LL * (unsigned int)result + 592);
          if ( v8 )
          {
            v9 = result;
            if ( *((_DWORD *)v8 - 1) != 1800103338 )
              __break(0x822Au);
            v8(v7);
            v4 = *(_DWORD *)(a1 + 196);
            result = v9;
          }
        }
      }
    }
    if ( v4 < 2 )
      break;
    v10 = *(_QWORD *)(a1 + 208);
    if ( v10 )
    {
      v11 = *(_QWORD *)(v10 + 416);
      if ( v11 )
      {
        if ( v10 == *(_QWORD *)(a1 + 328) && *(_DWORD *)(a1 + 648) == 2 )
        {
          if ( (unsigned int)result > 2 )
            goto LABEL_47;
          v12 = *(void (__fastcall **)(_QWORD))(v11 + 8 * v6 + 592);
          if ( v12 )
          {
            v13 = result;
            if ( *((_DWORD *)v12 - 1) != 1800103338 )
              __break(0x822Au);
            v12(v11);
            v4 = *(_DWORD *)(a1 + 196);
            result = v13;
          }
        }
      }
    }
    if ( v4 < 3 )
      break;
    v14 = *(_QWORD *)(a1 + 216);
    if ( v14 )
    {
      v15 = *(_QWORD *)(v14 + 416);
      if ( v15 )
      {
        if ( v14 == *(_QWORD *)(a1 + 328) && *(_DWORD *)(a1 + 648) == 2 )
        {
          if ( (unsigned int)result > 2 )
            goto LABEL_47;
          v16 = *(void (__fastcall **)(_QWORD))(v15 + 8 * v6 + 592);
          if ( v16 )
          {
            v17 = result;
            if ( *((_DWORD *)v16 - 1) != 1800103338 )
              __break(0x822Au);
            v16(v15);
            v4 = *(_DWORD *)(a1 + 196);
            result = v17;
          }
        }
      }
    }
    if ( v4 < 4 )
      break;
    v18 = *(_QWORD *)(a1 + 224);
    if ( !v18 )
      goto LABEL_46;
    v19 = *(_QWORD *)(v18 + 416);
    if ( !v19 || v18 != *(_QWORD *)(a1 + 328) || *(_DWORD *)(a1 + 648) != 2 )
      goto LABEL_46;
    if ( (unsigned int)result <= 2 )
    {
      v20 = *(__int64 (__fastcall **)(_QWORD))(v19 + 8 * v6 + 592);
      if ( v20 )
      {
        if ( *((_DWORD *)v20 - 1) != 1800103338 )
          __break(0x822Au);
        result = v20(v19);
        v4 = *(_DWORD *)(a1 + 196);
      }
LABEL_46:
      if ( v4 <= 4 )
        break;
    }
LABEL_47:
    __break(0x5512u);
LABEL_48:
    v21 = &unk_234896;
LABEL_51:
    printk(v21, "sde_encoder_get_kms");
    result = 0;
  }
  *(_BYTE *)(a1 + 1313) = 0;
  return result;
}
