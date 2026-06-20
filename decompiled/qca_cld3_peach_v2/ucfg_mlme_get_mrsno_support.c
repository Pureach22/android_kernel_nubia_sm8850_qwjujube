__int64 __fastcall ucfg_mlme_get_mrsno_support(__int64 a1, _BYTE *a2)
{
  __int64 psoc_ext_obj_fl; // x0
  char v4; // w8
  __int64 result; // x0

  psoc_ext_obj_fl = mlme_get_psoc_ext_obj_fl(a1);
  if ( psoc_ext_obj_fl )
  {
    v4 = *(_BYTE *)(psoc_ext_obj_fl + 2773);
    result = 0;
  }
  else
  {
    v4 = 0;
    result = 4;
  }
  *a2 = v4;
  return result;
}
