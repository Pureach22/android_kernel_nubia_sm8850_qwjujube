__int64 __fastcall cam_ife_csid_irq_0(__int64 a1, __int64 a2)
{
  if ( a2 )
    return cam_irq_controller_handle_irq(a1, *(_QWORD *)(a2 + 30984), 0);
  else
    return 0;
}
