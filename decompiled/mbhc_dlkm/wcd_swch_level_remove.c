bool __fastcall wcd_swch_level_remove(__int64 a1)
{
  return !*(_DWORD *)(*(_QWORD *)(a1 + 856) + 472LL)
      || (unsigned __int8)(snd_soc_component_read(*(_QWORD *)(a1 + 216)) & *(_BYTE *)(*(_QWORD *)(a1 + 856) + 476LL)) >> *(_BYTE *)(*(_QWORD *)(a1 + 856) + 477LL) != 0;
}
