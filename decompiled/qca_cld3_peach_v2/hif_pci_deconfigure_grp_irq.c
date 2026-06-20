__int64 __fastcall hif_pci_deconfigure_grp_irq(
        __int64 result,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8)
{
  __int64 v8; // x25
  unsigned __int64 v9; // x8
  __int64 v10; // x19
  __int64 v11; // x23
  __int64 v12; // x24
  __int64 v13; // x20
  int v14; // w8
  __int64 v15; // x0
  unsigned int v16; // w21

  v9 = *(unsigned int *)(result + 27264);
  if ( (_DWORD)v9 )
  {
    v10 = result;
    v11 = 0;
    v12 = result + 27120;
    while ( v11 != 18 )
    {
      v13 = *(_QWORD *)(v12 + 8 * v11);
      if ( *(_BYTE *)(v13 + 2682) == 1 )
      {
        v14 = *(_DWORD *)(v13 + 16);
        *(_BYTE *)(v13 + 2682) = 0;
        if ( v14 )
        {
          v8 = 0;
          while ( v8 != 25 )
          {
            v16 = *(_DWORD *)(v13 + 4 * v8 + 120);
            if ( *(_DWORD *)(v10 + 3984) )
              irq_modify_status(v16, 0x80000, 0);
            v15 = _irq_apply_affinity_hint(v16, 0, 1);
            qdf_status_from_os_return(v15);
            result = pld_srng_free_irq(*(_QWORD *)(*(_QWORD *)(v10 + 576) + 40LL), v16, v13);
            if ( ++v8 >= (unsigned __int64)*(unsigned int *)(v13 + 16) )
              goto LABEL_3;
          }
          break;
        }
LABEL_3:
        *(_DWORD *)(v13 + 16) = 0;
        v9 = *(unsigned int *)(v10 + 27264);
      }
      if ( ++v11 >= v9 )
        return result;
    }
    __break(0x5512u);
    *(double *)(v8 + 392) = a8;
    *(double *)(v8 + 400) = a2;
    return hif_pci_nointrs();
  }
  return result;
}
