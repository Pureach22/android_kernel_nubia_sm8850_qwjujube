// write access to const memory has been detected, the output may be wrong!
__int64 __fastcall ufs_qcom_set_esi_affinity_hint(__int64 result)
{
  __int64 v1; // x13
  __int64 v2; // x26
  __int64 v3; // x19
  __int64 desc; // x0
  unsigned int *v5; // x24
  int v6; // w20
  unsigned __int64 v7; // x8
  char *v8; // x25
  void *v9; // x25
  int v10; // t1
  int v11; // w0

  if ( result )
  {
    v2 = *(_QWORD *)(result + 184);
    v3 = result;
    if ( *(_QWORD *)(v2 + 736) )
    {
      msi_lock_descs(*(_QWORD *)(result + 64));
      desc = msi_domain_first_desc(*(_QWORD *)(v3 + 64), 0, 0);
      if ( desc )
      {
        v5 = (unsigned int *)desc;
        v6 = 0;
        do
        {
          v7 = *(unsigned int *)(*(_QWORD *)(v2 + 736) + 4LL * v6);
          v8 = (char *)&cpu_bit_bitmap + 8 * (v7 & 0x3F) - ((v7 >> 3) & 0x1FFFFFF8);
          v10 = *((_DWORD *)v8 + 2);
          v9 = v8 + 8;
          if ( (v10 & ~_cpu_possible_mask) != 0 )
          {
            dev_err(*(_QWORD *)(v3 + 64), "Invalid esi-cpu affinity mask passed, using default\n");
            v9 = &_cpu_possible_mask;
          }
          irq_modify_status(*v5, 0, 0x2000);
          v11 = _irq_apply_affinity_hint(*v5, v9, 1);
          if ( v11 < 0 )
            dev_err(
              *(_QWORD *)(v3 + 64),
              "%s: Failed to set affinity hint to cpu %d for ESI %d, err = %d\n",
              "ufs_qcom_set_esi_affinity_hint",
              v6,
              *v5,
              v11);
          ++v6;
          v5 = (unsigned int *)msi_next_desc(*(_QWORD *)(v3 + 64), 0, 0);
        }
        while ( v5 );
      }
      return msi_unlock_descs(*(_QWORD *)(v3 + 64));
    }
  }
  else
  {
    __break(0x800u);
    unk_0 = v1;
    return ufs_qcom_cpu_online(217);
  }
  return result;
}
