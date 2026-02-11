/* Digraphs:
<:   ->  [
:>   ->  ]
<%   ->  {
%>   ->  }
%:   ->  #
%:%: ->  ##
*/

%:include <stdio.h>

int main() <%
    int arr<:3:>;
    arr<:0:> = 10;
    arr<:1:> = 20;
    arr<:2:> = 30;

    for (int i = 0; i < 3; ++i)
        printf("arr[%d] = %d\n", i, arr[i]);

    %:define SIZE 3
    printf("SIZE = %d\n", SIZE);

    return 0;
%>