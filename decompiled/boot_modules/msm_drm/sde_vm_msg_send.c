__int64 __fastcall sde_vm_msg_send(__int64 a1)
{
  if ( a1 )
    return sde_vm_msgq_send();
  else
    return 4294967274LL;
}
