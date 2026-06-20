__int64 __fastcall cam_vfe_irq(__int64 a1, __int64 a2)
{
  if ( a2 )
    return cam_irq_controller_handle_irq(a1, *(_QWORD *)(*(_QWORD *)(a2 + 3680) + 8LL), 0);
  else
    return 0;
}
