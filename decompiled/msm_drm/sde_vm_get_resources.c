__int64 __fastcall sde_vm_get_resources(__int64 a1, __int64 a2)
{
  __int64 v3; // x21
  unsigned int io_resources; // w0
  unsigned int v5; // w20
  _QWORD *v7; // x20
  _QWORD *v8; // x21
  __int64 (__fastcall *v9)(__int64, __int64); // x8
  __int64 v10; // x1
  unsigned int v11; // w0
  unsigned int v12; // w20

  v3 = *(_QWORD *)(*(_QWORD *)(a1 + 136) + 56LL);
  io_resources = sde_kms_get_io_resources();
  if ( io_resources )
  {
LABEL_2:
    v5 = io_resources;
    msm_dss_clean_io_mem(a2 + 16);
    msm_dss_clean_io_irq(a2);
    return v5;
  }
  else
  {
    v7 = *(_QWORD **)(v3 + 5752);
    v8 = (_QWORD *)(v3 + 5752);
    while ( v7 != v8 )
    {
      v9 = (__int64 (__fastcall *)(__int64, __int64))*(v7 - 3);
      if ( v9 )
      {
        v10 = *(v7 - 1);
        if ( *((_DWORD *)v9 - 1) != 1931474520 )
          __break(0x8228u);
        v11 = v9(a2, v10);
        if ( v11 )
        {
          v12 = v11;
          printk(&unk_21BAF5, "sde_vm_get_resources");
          io_resources = v12;
          goto LABEL_2;
        }
      }
      v7 = (_QWORD *)*v7;
    }
    return 0;
  }
}
