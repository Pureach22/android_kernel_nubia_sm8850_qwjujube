__int64 __fastcall cam_csiphy_reset_phyconfig_param(__int64 result, __int64 a2, __int64 a3)
{
  __int64 v3; // x8
  unsigned int v4; // w19
  __int64 v5; // x20

  if ( (debug_mdl & 0x8000) != 0 && !debug_priority )
  {
    v4 = a2;
    v5 = result;
    ((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      (unsigned __int16)debug_mdl & 0x8000,
      4,
      "cam_csiphy_reset_phyconfig_param",
      469,
      "Resetting phyconfig param at index: %d",
      a2);
    result = v5;
    a2 = v4;
    if ( v4 < 3 )
      goto LABEL_4;
  }
  else if ( (unsigned int)a2 < 3 )
  {
LABEL_4:
    v3 = result + 104LL * (unsigned int)a2;
    *(_WORD *)(v3 + 628) = 0;
    *(_QWORD *)(v3 + 600) = 0;
    *(_QWORD *)(v3 + 608) = 0;
    *(_QWORD *)(v3 + 616) = 0;
    *(_DWORD *)(v3 + 648) = -1;
    *(_DWORD *)(v3 + 624) = -1;
    *(_DWORD *)(v3 + 684) = -1;
    *(_WORD *)(v3 + 688) = 0;
    *(_QWORD *)(v3 + 696) = 0;
    *(_BYTE *)(v3 + 690) = 0;
    return result;
  }
  __break(0x5512u);
  return cam_csiphy_program_common_registers(result, a2, a3);
}
