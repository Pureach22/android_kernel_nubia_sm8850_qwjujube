__int64 __fastcall gpr_device_remove(__int64 result)
{
  __int64 v1; // x8
  void (*v2)(void); // x8
  __int64 v3; // x19
  __int64 v4; // x20

  v1 = *(_QWORD *)(result + 136);
  if ( v1 )
  {
    v2 = *(void (**)(void))(v1 - 16);
    v3 = result;
    v4 = *(_QWORD *)(*(_QWORD *)(result + 96) + 152LL);
    if ( v2 )
    {
      if ( *((_DWORD *)v2 - 1) != -465457219 )
        __break(0x8228u);
      v2();
    }
    raw_spin_lock(v4 + 24);
    idr_remove(v4 + 32, *(unsigned __int16 *)(v3 + 912));
    return raw_spin_unlock(v4 + 24);
  }
  return result;
}
