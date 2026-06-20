__int64 __fastcall sde_kms_init_shared_hw(__int64 a1)
{
  __int64 result; // x0
  __int64 v3; // x1
  __int64 v4; // x8
  __int64 (__fastcall *v5)(__int64, __int64); // x8

  result = *(_QWORD *)(a1 + 3528);
  if ( result )
  {
    v3 = *(_QWORD *)(a1 + 152);
    if ( v3 )
    {
      v4 = *(unsigned int *)(result + 28);
      if ( (unsigned int)v4 >= 3 )
      {
        __break(0x5512u);
        return sde_kms_set_lutdma_vbif_remap(result);
      }
      else
      {
        v5 = *(__int64 (__fastcall **)(__int64, __int64))(result + 8 * v4 + 224);
        if ( v5 )
        {
          if ( *((_DWORD *)v5 - 1) != 422924813 )
            __break(0x8228u);
          return v5(result, v3);
        }
      }
    }
  }
  return result;
}
