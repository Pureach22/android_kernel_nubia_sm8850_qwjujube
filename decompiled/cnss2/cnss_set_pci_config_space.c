_QWORD *__fastcall cnss_set_pci_config_space(_QWORD *result, char a2)
{
  __int64 v2; // x8
  __int64 v3; // x19
  __int64 v4; // x8
  _QWORD *v5; // x20
  __int64 v6; // t1

  v2 = result[1];
  if ( v2 )
  {
    v3 = *result;
    if ( *((_BYTE *)result + 49) )
    {
      if ( (a2 & 1) == 0 )
        goto LABEL_12;
    }
    else
    {
      v4 = *(_QWORD *)(v2 + 552);
      if ( (a2 & 1) == 0 )
      {
        if ( (v4 & 0x200) == 0 )
        {
          v6 = result[7];
          result += 7;
          if ( !v6 )
            return result;
          pci_load_and_free_saved_state(v3, result);
          return (_QWORD *)pci_restore_state(v3);
        }
LABEL_12:
        pci_load_saved_state(*result, result[8]);
        return (_QWORD *)pci_restore_state(v3);
      }
      if ( (v4 & 0x200) == 0 )
      {
        v5 = result;
        pci_save_state(*result);
        result = (_QWORD *)pci_store_saved_state(v3);
        v5[7] = result;
        return result;
      }
    }
    result[7] = 0;
  }
  return result;
}
