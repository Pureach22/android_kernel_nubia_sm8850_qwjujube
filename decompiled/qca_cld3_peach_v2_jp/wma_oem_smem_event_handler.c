__int64 __fastcall wma_oem_smem_event_handler(__int64 a1, __int64 a2, __int64 a3)
{
  void (__fastcall *v6)(_QWORD); // x8

  if ( *(_BYTE *)(cfg_psoc_get_values(*(_QWORD *)(a1 + 24)) + 3909) == 1 )
  {
    if ( (unsigned int)pmo_get_wow_suspend_type(*(_QWORD *)(a1 + 24)) )
    {
      v6 = *(void (__fastcall **)(_QWORD))(a2 + 14568);
      if ( v6 )
      {
LABEL_4:
        if ( *((_DWORD *)v6 - 1) != 1641065772 )
          __break(0x8228u);
        v6(a3);
      }
    }
    else
    {
      v6 = *(void (__fastcall **)(_QWORD))(a2 + 14576);
      if ( v6 )
        goto LABEL_4;
    }
    return 0;
  }
  return 16;
}
