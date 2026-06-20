__int64 __fastcall drm_dp_set_subconnector_property(__int64 a1, int a2, _BYTE *a3, _BYTE *a4)
{
  __int64 v4; // x2
  __int64 v5; // x8
  _QWORD *v6; // x9

  if ( a2 != 1 )
    goto LABEL_8;
  if ( (a3[5] & 1) != 0 )
  {
    if ( *a3 == 16 )
    {
      v5 = a3[5] & 6;
      if ( (unsigned int)v5 < 5 )
      {
        v6 = &unk_1D608;
LABEL_11:
        v4 = v6[v5];
        return drm_object_property_set_value(a1 + 64, *(_QWORD *)(*(_QWORD *)a1 + 1304LL), v4);
      }
    }
    else
    {
      v5 = *a4 & 7;
      if ( (_DWORD)v5 != 7 )
      {
        v6 = &unk_1D630;
        goto LABEL_11;
      }
    }
LABEL_8:
    v4 = 0;
    return drm_object_property_set_value(a1 + 64, *(_QWORD *)(*(_QWORD *)a1 + 1304LL), v4);
  }
  v4 = 15;
  return drm_object_property_set_value(a1 + 64, *(_QWORD *)(*(_QWORD *)a1 + 1304LL), v4);
}
