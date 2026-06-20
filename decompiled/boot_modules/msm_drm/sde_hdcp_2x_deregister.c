__int64 __fastcall sde_hdcp_2x_deregister(__int64 result)
{
  __int64 v1; // x19

  if ( result )
  {
    v1 = result;
    kthread_stop(*(_QWORD *)(result + 216));
    if ( *(_QWORD *)(v1 + 152) )
    {
      hdcp2_deinit();
      *(_QWORD *)(v1 + 152) = 0;
    }
    return kfree(v1);
  }
  return result;
}
