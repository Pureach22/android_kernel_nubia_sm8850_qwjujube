__int64 __fastcall cam_vfe_top_acquire_resource(__int64 a1, __int64 a2)
{
  __int64 v2; // x9
  __int64 v3; // x8
  int v4; // w10
  int v5; // w9
  int v6; // w10

  v2 = *(_QWORD *)(a1 + 24);
  v3 = v2 + 20480;
  *(_DWORD *)(v2 + 22668) = *(_DWORD *)(a2 + 80);
  *(_QWORD *)(v2 + 80) = *(_QWORD *)(a2 + 24);
  v4 = *(unsigned __int8 *)(v2 + 22811);
  *(_QWORD *)(v2 + 88) = *(_QWORD *)(a2 + 16);
  if ( v4 == 1 )
  {
    *(_DWORD *)(v2 + 22676) = *(_DWORD *)(*(_QWORD *)(a2 + 88) + 76LL);
    *(_DWORD *)(v2 + 22672) = *(_DWORD *)(*(_QWORD *)(a2 + 88) + 128LL);
    *(_DWORD *)(v2 + 22680) = *(_DWORD *)(*(_QWORD *)(a2 + 88) + 84LL);
    *(_DWORD *)(v2 + 22688) = *(_DWORD *)(*(_QWORD *)(a2 + 88) + 88LL);
    *(_DWORD *)(v2 + 22684) = *(_DWORD *)(*(_QWORD *)(a2 + 88) + 108LL);
    *(_DWORD *)(v2 + 22692) = *(_DWORD *)(*(_QWORD *)(a2 + 88) + 112LL);
    *(_BYTE *)(v2 + 22808) = *(_BYTE *)(a2 + 96);
    *(_BYTE *)(v2 + 22809) = *(_BYTE *)(a2 + 97);
    v5 = *(_DWORD *)(a2 + 64);
    *(_DWORD *)(v3 + 2244) = v5;
    *(_DWORD *)(v3 + 2236) = *(_DWORD *)(*(_QWORD *)(a2 + 88) + 156LL);
    v6 = *(_DWORD *)(*(_QWORD *)(a2 + 88) + 148LL);
    *(_QWORD *)(v3 + 2216) = 0;
    *(_DWORD *)(v3 + 2232) = v6;
    *(_BYTE *)(v3 + 2332) = *(_BYTE *)(*(_QWORD *)(a2 + 88) + 219LL);
    *(_BYTE *)(v3 + 2334) = *(_BYTE *)(a2 + 98);
    if ( v5 )
      *(_DWORD *)(v3 + 2240) = *(_DWORD *)(a2 + 60);
  }
  if ( (debug_mdl & 8) == 0 || debug_priority )
    return 0;
  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
    3,
    debug_mdl & 8,
    4,
    "cam_vfe_top_acquire_resource",
    1305,
    "VFE:%u Res:[id:%d name:%s] dsp_mode:%d is_dual:%d dual_hw_idx:%d",
    *(_DWORD *)(*(_QWORD *)(a1 + 16) + 4LL),
    *(_DWORD *)(a1 + 4),
    (const char *)(a1 + 128),
    *(_DWORD *)(v3 + 2192),
    *(_DWORD *)(v3 + 2244),
    *(_DWORD *)(v3 + 2240));
  return 0;
}
