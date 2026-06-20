__int64 __fastcall hif_pci_disable_bus(__int64 result)
{
  __int64 v1; // x19
  double v2; // d0
  double v3; // d1
  double v4; // d2
  double v5; // d3
  double v6; // d4
  double v7; // d5
  double v8; // d6
  double v9; // d7
  void (__fastcall *v10)(_QWORD); // x8

  if ( result )
  {
    v1 = result;
    if ( *(_DWORD *)(result + 16) >> 1 == 545259702 )
    {
      hif_pci_device_warm_reset();
      if ( !*(_QWORD *)(v1 + 30720) )
        return qdf_trace_msg(0x3Du, 5u, "%s: X", v2, v3, v4, v5, v6, v7, v8, v9, "hif_pci_disable_bus");
    }
    else
    {
      hif_pci_device_reset();
      if ( !*(_QWORD *)(v1 + 30720) )
        return qdf_trace_msg(0x3Du, 5u, "%s: X", v2, v3, v4, v5, v6, v7, v8, v9, "hif_pci_disable_bus");
    }
    hif_dump_pipe_debug_count(v1);
    if ( *(_BYTE *)(v1 + 736) == 1 )
    {
      athdiag_procfs_remove();
      *(_BYTE *)(v1 + 736) = 0;
    }
    v10 = *(void (__fastcall **)(_QWORD))(v1 + 31192);
    if ( *((_DWORD *)v10 - 1) != -37903589 )
      __break(0x8228u);
    v10(v1);
    *(_QWORD *)(v1 + 40) = 0;
    return qdf_trace_msg(0x3Du, 5u, "%s: X", v2, v3, v4, v5, v6, v7, v8, v9, "hif_pci_disable_bus");
  }
  return result;
}
