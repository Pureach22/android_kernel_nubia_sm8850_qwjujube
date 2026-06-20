__int64 __fastcall cam_sfe_bus_wr_handle_bus_irq(__int64 a1, __int64 a2)
{
  if ( (unsigned int)cam_irq_controller_handle_irq(a1, *(_QWORD *)(*(_QWORD *)a2 + 40LL), 0) == 1 )
    return 0;
  else
    return 4294967274LL;
}
