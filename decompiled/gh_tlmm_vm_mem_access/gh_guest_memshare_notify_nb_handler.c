__int64 __fastcall gh_guest_memshare_notify_nb_handler(__int64 a1, __int64 a2, unsigned __int16 *a3)
{
  __int64 *v3; // x20
  __int16 v5; // w21
  _WORD *v6; // x0
  _WORD *v7; // x19

  if ( a2 == 1443889160 && *((_BYTE *)a3 + 4) == 3 && *((_BYTE *)a3 + 5) )
  {
    v3 = (__int64 *)(a1 + 104);
    while ( 1 )
    {
      v3 = (__int64 *)*v3;
      if ( v3 == (__int64 *)(a1 + 104) )
        break;
      if ( *a3 == *((unsigned __int16 *)v3 + 14) )
      {
        if ( (unsigned int)gh_rm_get_vm_name(*a3, v3 + 3) )
        {
          dev_err(*(_QWORD *)(a1 - 32), "Failed to get VM name for VMID%d\n", *((unsigned __int16 *)v3 + 14));
        }
        else
        {
          v5 = *((_WORD *)v3 + 14);
          v6 = (_WORD *)_kmalloc_cache_noprof(ghd_rm_mem_share, 3520, 8);
          v7 = v6;
          if ( v6 )
          {
            v6[2] = v5;
            *v6 = 1;
            if ( (unsigned int)gh_rm_mem_notify(*((unsigned int *)v3 + 9), 1, 3, v6) )
              printk(&unk_72B2);
            else
              kfree(v7);
          }
        }
        return 0;
      }
    }
  }
  return 0;
}
