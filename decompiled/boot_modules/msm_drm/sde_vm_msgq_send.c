__int64 __fastcall sde_vm_msgq_send(__int64 a1, __int64 a2, unsigned __int64 a3)
{
  if ( *(_QWORD *)(a1 + 256) )
  {
    if ( a3 >= 0xF1 )
    {
      printk(&unk_24B377, "sde_vm_msgq_send");
      return 4294967289LL;
    }
    else
    {
      return gh_msgq_send();
    }
  }
  else
  {
    printk(&unk_247F8D, "sde_vm_msgq_send");
    return 4294967274LL;
  }
}
