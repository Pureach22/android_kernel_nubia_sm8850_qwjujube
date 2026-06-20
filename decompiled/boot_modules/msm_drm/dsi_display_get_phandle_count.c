__int64 __fastcall dsi_display_get_phandle_count(_QWORD *a1, char *a2)
{
  if ( a1[198] )
    return dsi_parser_count_u32_elems(a1[35], a2);
  else
    return of_property_count_elems_of_size(a1[34], a2, 4);
}
