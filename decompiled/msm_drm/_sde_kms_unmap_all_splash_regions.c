__int64 __fastcall sde_kms_unmap_all_splash_regions(__int64 result)
{
  __int64 v1; // x19
  __int64 v2; // x1

  if ( *(_DWORD *)(result + 2540) )
  {
    v1 = result;
    if ( *(_DWORD *)(result + 2544) )
    {
      result = sde_kms_splash_mem_put(result);
      if ( (_DWORD)result )
      {
        result = printk(&unk_27DC1E, "_sde_kms_unmap_all_splash_regions");
        if ( !*(_QWORD *)(v1 + 2736) )
          goto LABEL_7;
      }
      else if ( !*(_QWORD *)(v1 + 2736) )
      {
        goto LABEL_7;
      }
      result = sde_kms_splash_mem_put(v1);
      if ( (_DWORD)result )
        result = printk(&unk_27DC57, "_sde_kms_unmap_all_splash_regions");
LABEL_7:
      if ( *(_DWORD *)(v1 + 2544) < 2u )
        return result;
      result = sde_kms_splash_mem_put(v1);
      if ( (_DWORD)result )
      {
        result = printk(&unk_27DC1E, "_sde_kms_unmap_all_splash_regions");
        v2 = *(_QWORD *)(v1 + 2816);
        if ( v2 )
        {
LABEL_10:
          result = sde_kms_splash_mem_put(v1);
          if ( (_DWORD)result )
            result = printk(&unk_27DC57, "_sde_kms_unmap_all_splash_regions");
        }
      }
      else
      {
        v2 = *(_QWORD *)(v1 + 2816);
        if ( v2 )
          goto LABEL_10;
      }
      if ( *(_DWORD *)(v1 + 2544) > 2u )
      {
        __break(0x5512u);
        return sde_kms_splash_mem_get(result, v2);
      }
    }
  }
  return result;
}
