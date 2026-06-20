bool reg_last_request_cell_base()
{
  return *((_DWORD *)last_request + 5) == 1 && *((_DWORD *)last_request + 6) == 1;
}
