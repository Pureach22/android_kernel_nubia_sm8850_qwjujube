__int64 __fastcall hif_pci_set_grp_intr_affinity(
        __int64 result,
        unsigned int a2,
        unsigned int a3,
        char a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  unsigned __int64 v12; // x8
  __int64 v15; // x21
  unsigned __int64 v16; // x24
  unsigned __int64 v17; // x25
  __int64 v18; // x26
  __int64 v19; // x22

  v12 = *(unsigned int *)(result + 27264);
  if ( (_DWORD)v12 )
  {
    v15 = result;
    v16 = 0;
    v17 = a2;
    v18 = result + 27120;
    do
    {
      if ( ((v17 >> v16) & 1) != 0 )
      {
        if ( v16 >= 0x12 )
        {
          __break(0x5512u);
          return hif_pci_reg_read32();
        }
        v19 = *(_QWORD *)(v18 + 8 * v16);
        result = hif_pci_irq_set_affinity_hint(v19, a3, a4 & 1, a5, a6, a7, a8, a9, a10, a11, a12);
        *(_DWORD *)(v19 + 2928) = -1;
        v12 = *(unsigned int *)(v15 + 27264);
      }
      ++v16;
    }
    while ( v16 < v12 );
  }
  return result;
}
