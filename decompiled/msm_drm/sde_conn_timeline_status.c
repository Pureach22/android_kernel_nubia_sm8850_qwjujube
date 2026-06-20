__int64 __fastcall sde_conn_timeline_status(__int64 a1)
{
  if ( a1 )
    return sde_fence_timeline_status(*(_QWORD *)(a1 + 2864), a1 + 64);
  else
    return printk(&unk_242658, "sde_conn_timeline_status");
}
