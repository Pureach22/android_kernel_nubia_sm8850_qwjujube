__int64 __fastcall sde_cesta_destroy_client(__int64 result)
{
  __int64 v1; // x20
  __int64 v2; // x19
  _QWORD *v3; // x8
  __int64 v4; // x9
  __int64 v5; // x10

  v2 = result;
  if ( !result || *(_DWORD *)(result + 4) )
  {
    result = printk(&unk_251286, "sde_cesta_destroy_client");
    if ( *(_DWORD *)(v2 + 4) )
    {
      __break(0x5512u);
LABEL_11:
      _list_del_entry_valid_or_report(v4);
      goto LABEL_7;
    }
  }
  v1 = cesta_list_0;
  if ( !cesta_list_0 )
    return result;
  mutex_lock(cesta_list_0 + 800);
  v3 = *(_QWORD **)(v2 + 112);
  v4 = v2 + 104;
  if ( *v3 != v2 + 104 )
    goto LABEL_11;
  v5 = *(_QWORD *)v4;
  if ( *(_QWORD *)(*(_QWORD *)v4 + 8LL) != v4 )
    goto LABEL_11;
  *(_QWORD *)(v5 + 8) = v3;
  *v3 = v5;
LABEL_7:
  *(_QWORD *)(v2 + 104) = v2 + 104;
  *(_QWORD *)(v2 + 112) = v4;
  return mutex_unlock(v1 + 800);
}
