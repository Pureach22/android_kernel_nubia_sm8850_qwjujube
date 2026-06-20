__int64 __fastcall msm_vidc_get_control(__int64 a1, __int64 a2)
{
  int cap_id; // w21
  __int64 v5; // x4
  __int64 v6; // x3
  void *v7; // x0
  __int64 result; // x0
  __int64 v9; // x4
  void *v10; // x0
  __int64 v11; // x8
  __int64 v12; // x22
  __int64 v13; // x21
  const char *v14; // x1
  __int64 v15; // x8
  __int64 (__fastcall *v16)(__int64, __int64); // x8
  __int64 v17; // x0

  cap_id = msm_vidc_get_cap_id(a1, *(_DWORD *)(a2 + 72));
  if ( !is_valid_cap_id(cap_id) )
  {
    if ( a1 && (msm_vidc_debug & 1) != 0 )
      printk(&unk_90497, "err ", a1 + 340, "msm_vidc_get_control", *(_QWORD *)(a2 + 80));
    return 4294967274LL;
  }
  if ( cap_id > 147 )
  {
    if ( cap_id > 163 )
    {
      if ( cap_id == 164 )
      {
        v9 = *(unsigned int *)(a1 + 31904);
        *(_DWORD *)(a2 + 196) = v9;
        if ( !a1 || (msm_vidc_debug & 2) == 0 )
          return 0;
        v10 = &unk_93B9C;
        goto LABEL_46;
      }
      if ( cap_id == 177 )
      {
        v9 = *(unsigned int *)(a1 + 34088);
        *(_DWORD *)(a2 + 196) = v9;
        if ( !a1 || (msm_vidc_debug & 2) == 0 )
          return 0;
        v10 = &unk_8682A;
        goto LABEL_46;
      }
    }
    else
    {
      if ( cap_id == 148 )
      {
        v9 = *(unsigned int *)(a1 + 29216);
        *(_DWORD *)(a2 + 196) = v9;
        if ( !a1 || (msm_vidc_debug & 2) == 0 )
          return 0;
        v10 = &unk_84200;
        goto LABEL_46;
      }
      if ( cap_id == 163 )
      {
        v9 = *(unsigned int *)(a1 + 31736);
        *(_DWORD *)(a2 + 196) = v9;
        if ( !a1 || (msm_vidc_debug & 2) == 0 )
          return 0;
        v10 = &unk_91641;
        goto LABEL_46;
      }
    }
LABEL_48:
    if ( a1 && (msm_vidc_debug & 1) != 0 )
      printk(&unk_92F93, "err ", a1 + 340, *(_QWORD *)(a2 + 80), *(unsigned int *)(a2 + 72));
    return 4294967274LL;
  }
  if ( cap_id <= 106 )
  {
    if ( cap_id == 83 )
    {
      v6 = (unsigned int)(*(_DWORD *)(a1 + 2524) + *(_DWORD *)(a1 + 2520));
      *(_DWORD *)(a2 + 196) = v6;
      if ( a1 && (msm_vidc_debug & 2) != 0 )
      {
        v7 = &unk_8B570;
        goto LABEL_32;
      }
      return 0;
    }
    if ( cap_id == 84 )
    {
      v6 = (unsigned int)(*(_DWORD *)(a1 + 2564) + *(_DWORD *)(a1 + 2560));
      *(_DWORD *)(a2 + 196) = v6;
      if ( a1 && (msm_vidc_debug & 2) != 0 )
      {
        v7 = &unk_8BF99;
LABEL_32:
        printk(v7, "high", a1 + 340, v6, v5);
        return 0;
      }
      return 0;
    }
    goto LABEL_48;
  }
  if ( cap_id != 107 )
  {
    if ( cap_id == 147 )
    {
      v9 = *(unsigned int *)(a1 + 29048);
      *(_DWORD *)(a2 + 196) = v9;
      if ( !a1 || (msm_vidc_debug & 2) == 0 )
        return 0;
      v10 = &unk_91676;
LABEL_46:
      v14 = "high";
      goto LABEL_47;
    }
    goto LABEL_48;
  }
  v11 = *(_QWORD *)(a1 + 320);
  *(_DWORD *)(a2 + 196) = -1;
  v12 = *(unsigned int *)(a1 + 21992);
  v13 = a1 + 38352;
  do
  {
    v13 = *(_QWORD *)v13;
    if ( v13 == a1 + 38352 )
    {
      if ( !a1 )
        return 0;
      if ( (msm_vidc_debug & 4) != 0 )
        printk(&unk_97882, "low ", a1 + 340, "msm_vidc_get_fence_from_id", *(unsigned int *)(a1 + 21992));
LABEL_55:
      if ( (msm_vidc_debug & 4) != 0 )
        printk(&unk_8D9C1, "low ", a1 + 340, "msm_vidc_get_output_tx_fence_fd", v12);
      goto LABEL_57;
    }
  }
  while ( *(_QWORD *)(v13 + 160) != v12 );
  if ( !v13 )
  {
    if ( !a1 )
      return 0;
    goto LABEL_55;
  }
  if ( *(_DWORD *)(v13 + 152) == -1 )
  {
    if ( v11
      && (v15 = *(_QWORD *)(v11 + 6584)) != 0
      && (v16 = *(__int64 (__fastcall **)(__int64, __int64))(v15 + 32)) != nullptr )
    {
      if ( *((_DWORD *)v16 - 1) != -1495712865 )
        __break(0x8228u);
      result = v16(a1, v13);
      if ( (_DWORD)result )
        return result;
      v17 = *(unsigned int *)(v13 + 152);
    }
    else
    {
      v17 = 0xFFFFFFFFLL;
    }
    fd_install(v17, **(_QWORD **)(v13 + 256));
    if ( !a1 )
    {
      *(_DWORD *)(a2 + 196) = *(_DWORD *)(v13 + 152);
      return 0;
    }
    if ( (msm_vidc_debug & 2) != 0 )
      printk(&unk_915A6, "high", a1 + 340, "create_fd", v13 + 16);
    *(_DWORD *)(a2 + 196) = *(_DWORD *)(v13 + 152);
  }
  else
  {
    *(_DWORD *)(a2 + 196) = *(_DWORD *)(v13 + 152);
    if ( !a1 )
      return 0;
  }
LABEL_57:
  if ( (msm_vidc_debug & 4) == 0 )
    return 0;
  v9 = *(unsigned int *)(a2 + 196);
  v10 = &unk_978BC;
  v14 = "low ";
LABEL_47:
  printk(v10, v14, a1 + 340, "msm_vidc_get_control", v9);
  return 0;
}
