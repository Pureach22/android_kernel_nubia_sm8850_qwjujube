__int64 __fastcall swr_register_master(__int64 a1)
{
  unsigned int id; // w0
  __int64 v3; // x2
  unsigned int v4; // w20
  unsigned int v5; // w0

  mutex_lock(&swr_lock);
  id = of_alias_get_id(*(_QWORD *)(a1 + 744), "swr");
  if ( (id & 0x80000000) != 0 )
  {
    v3 = *(unsigned int *)(a1 + 928);
  }
  else
  {
    v3 = id;
    *(_DWORD *)(a1 + 928) = id;
  }
  v4 = idr_alloc(&master_idr, a1, v3, (unsigned int)(v3 + 1), 3264);
  mutex_unlock(&swr_lock);
  if ( (v4 & 0x80000000) == 0 )
  {
    *(_DWORD *)(a1 + 928) = v4;
    dev_set_name(a1, "swr%u", v4);
    *(_QWORD *)(a1 + 120) = &swr_master_type;
    *(_QWORD *)(a1 + 128) = &soundwire_type;
    _mutex_init(a1 + 936, "&master->mlock", &swr_register_master___key);
    v5 = device_register(a1);
    if ( (v5 & 0x80000000) != 0 )
    {
      v4 = v5;
      idr_remove(&master_idr, *(unsigned int *)(a1 + 928));
    }
    else
    {
      v4 = 0;
      *(_QWORD *)(a1 + 984) = a1 + 984;
      *(_QWORD *)(a1 + 992) = a1 + 984;
    }
  }
  return v4;
}
